/*
	假设(u,v)是一个双径岛屿对，那么对于这两条长度同为 l-1 的路径，不妨设为：
	x1,x2,x3,x4,...,xl ，有 x1=u,xl=v;
	y1,y2,y3,y4,...,yl
	我们现在用反证法证明这两个路径有且仅有一个落脚点不同，假设有两个个落脚点不同，那么可以
	从中任意取两个：
	1） 如果这两个落脚点不相邻，xi!=yi & xj!=y_j (j-i>1)，x,y其他元素对应相等：
		钦定 x_i>y_i，那么 x(i+1)>y(i+1)，否则 x1,...xi,y(i+1),...,xl也合法 
	 	这样 x1,...xi,y(i+1),...,xl也合法 
	对于有多个落脚点不同,我们也同样钦定这个不同点 x>y，那么一样可以从 xi跳到
	y(i+1)，这就是一条新的路。
	
	得证，(u,v)若为一个双径岛屿对，那么两个路径有且仅有一个落脚点不相同，显然这个两个
	不同的落脚点一定相邻，如果不相邻那么钦定 x_i<t<y_i，则 x1,x2,...t,...,xl也合法。 
	
	现在要找的是这样一个东西： (u,v,w)对使得 u->v->w与 u-> v+1 ->w是(u,w)的两个@，
	要保证 不存在x>=u&&y<=w 使得 (x,y）满足条件，显然 u跳两次到 w。
	改变考虑的枚举，枚举 v，令 r_i表示从 i 一步跳到的最右边的岛编号，l_i反之：
	这两个序列利用单指针平移做即可 
	则若 v是一个(u,w）的v要满足：l[v-1]!=l[v],r[v+2]!=r[v+1],l[v]=l[v+1],r[v]=r[v+1]；
	那么 u=l[v],v=r[v]; 
	 
	对于所有的 (u,w)，所有能够x以唯一最短路径跳到 u 并且可以由w唯一路径跳到的y的对(x,y)
	都合法。
	令 f_i 表示从 (0,i-1)可以以唯一路径跳到 i 的点的数量，g_i表示从i可以唯一路径跳到的点数 
	ans= \sum(u,w) f[u]*g[w]
	f和 g可以直接递推来求，每一步都必须尽力往后跳，还有一些散点就是一步可以到 i的那些不
	用尽力跳的，可以二分求也可以指针。 
*/

#include<bits/stdc++.h>

#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define int long long
using namespace std;
const int N=2e6+10;
int n;
ll d,x[N];
int L[N],R[N],f[N],g[N];
bool same(int x,int y){
	return L[x]==L[y]&&R[x]==R[y];
}
ll ans;
void solve(){
	ans=0;
//	cout<<endl<<endl<<endl;
	cin>>n>>d;
	for(int i=0;i<=n+1;i++)f[i]=g[i]=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	
//	for(int i=1;i<=n;i++)x[i]/=100000000000000000;
//	d/=100000000000000000;
//	for(int i=1;i<=n;i++)cout<<x[i]<<' ';
//	cout<<" d="<<d<<endl;
	
	for(int r=1,i=1;i<=n;i++){
		while(r+1<=n&&x[r+1]-x[i]<=d)++r;
		R[i]=r;	
	}
	for(int l=n,i=n;i>=1;i--){
		while(l-1>=1&&x[i]-x[l-1]<=d)--l;
		L[i]=l;
	}
	for(int i=1;i<n;i++){
		f[i]++;
		f[R[i]]+=f[i];
	}
	f[n]++;
	for(int i=n;i>1;i--){
		g[i]++;
		g[L[i]]+=g[i];
	}
	g[1]++;
//	cout<<"L"<<endl;
//	for(int i=1;i<=n;i++)cout<<L[i]<<' ';
//	cout<<endl<<"R"<<endl;
//	for(int i=1;i<=n;i++)cout<<R[i]<<' ';
//	cout<<endl<<"f"<<endl;
//	for(int i=1;i<=n;i++)cout<<f[i]<<' ';
//	cout<<endl<<"g"<<endl;
//	for(int i=1;i<=n;i++)cout<<g[i]<<' '; 
//	cout<<endl;
	for(int i=2;i<n-1;i++){
		ll tmp=0;
		if(R[i]==i+1||L[i+1]==i)continue;
		if(R[L[i+1]]>=i+2)continue;
		if(L[R[i]]<=i-1)continue;
		if(same(i,i+1)&&(!same(i,i-1))&&(!same(i+1,i+2))){ 
			int x=L[i],y=R[i];
			int cntx=f[x]+(x-L[x]-1),cnty=g[y]+(R[y]-y-1);
			if(R[y]==y)cnty++;
			if(L[x]==x)cntx++;
			tmp+=1LL*cntx*cnty;
			// 找到最小的 i+1<r<=R[i] St:L[r]=i ans+=[r,R[i]-1]*cntx
			int l=i+2,r=R[i];
			while(l<r){
				int mid=l+r>>1;
				if(L[mid]==i)r=mid;
				else l=mid+1; 
			}
			tmp+=1LL*cntx*(R[i]-l);
			 //找最大的 L[i]<=l<i St:R[l]=i+1 ans+=[L[i]+1,l]*cntx;
			l=L[i],r=i-1;
			while(l<r){
				int mid=l+r+1>>1;
				if(R[mid]==i+1)l=mid;
				else r=mid-1;
			}
			tmp+=1LL*cnty*(l-L[i]);
		}
		else if(L[i]==L[i+1]&&L[i+2]!=L[i+1]&&L[i-1]!=L[i]){
//				cout<<"typ2\n";
			int x=L[i];
			int cntx=f[x]+(x-L[x]-1);
			if(L[x]==x)cntx=0;
			tmp+=cntx*(R[i]-R[i-1]);
		}
		else if(R[i]==R[i+1]&&R[i+2]!=R[i+1]&&R[i-1]!=R[i]){
//			cout<<"typ3\n";	
			int y=R[i];
			int cnty=g[y]+(R[y]-y-1);
			if(R[y]==y)cnty=0;
			tmp+=cnty*(L[i+2]-L[i+1]);
		}
		else{
			if(R[i]==i+1||L[i+1]==i)continue;
//			cout<<"typ4\n";
			int x=L[i],y=R[i];
			//左边找i+1可达i+2不可达的，右边找i可达 i-1不可达的
			tmp+=1LL*(L[i+2]-L[i+1])*(R[i]-R[i-1]); 
		}
//		cout<<"i="<<i<<" tans="<<tmp<<endl;
		ans+=tmp;
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int _T,c;
	cin>>c;
	cin>>_T;
	while(_T--)solve();

	return 0;
}


