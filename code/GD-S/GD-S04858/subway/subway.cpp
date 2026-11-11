#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=510,M=2e4+10,maxn=1e6;
int sub,n,m,d,op,w[M],a[N][M],t[N][M];
int tai[M],kou[M],ting[N][M],subid;
int tg[maxn],hd[maxn],nxt[maxn],idx,len[maxn];
int ans[maxn],vis[maxn],dp[maxn];
struct lst{
	int x,y,id;
	bool operator<(const lst&B) const{
		return x<B.x;
	} 
}s[maxn];
struct node{
	int val,pos;
	bool operator<(const node&B) const{
		return val<B.val;
	} 
};
priority_queue<node> q;
void link(int x,int y,int z){
	tg[++idx]=y;
	nxt[idx]=hd[x];
	hd[x]=idx;
	len[idx]=z;
} 
void bdmap(){
	for(int i=1;i<=m;i++){
		tai[i]=++subid;
		kou[i]=++subid;
		for(int j=1;j<=n;j++){
			ting[j][i]=++subid;
		}
	}
	for(int i=1;i<=m;i++){
//		cout<<"kou"<<kou[i]<<" tai"<<tai[i]<<endl;
		for(int j=1;j<=n;j++){
	//		cout<<"line"<<j<<" ting"<<ting[j][i]<<endl;
		}
	//	cout<<endl;
	}
}
void init(){
	for(int i=1;i<=subid;i++){
		vis[i]=0;
		dp[i]=0;
	}
	while(q.size()>0){
		q.pop();
	}
}
void dj(int st){
	q.push({0,st});
	while(q.size()>0){
		node np=q.top();
		int x=np.pos;
		q.pop();
		if(vis[x])	continue;
		//cout<<x<<","<<np.val<<endl;
		vis[x]=1;
		dp[x]=np.val;
		for(int i=hd[x];i;i=nxt[i]){
			int y=tg[i];
			if(vis[y])	continue;
			q.push({np.val+len[i],y});
				
		}
	}	
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>sub>>n>>m>>d>>op;
	bdmap();
	for(int i=1;i<=m;i++){
		cin>>w[i];
		link(kou[i],tai[i],w[i]);
		link(tai[i],kou[i],w[i]); 
	//	cout<<i<<"kou"<<kou[i]<<" "<<i<<"tai"<<tai[i]<<endl;
	}	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];	
			if(j!=1){
				link(ting[i][a[i][j]],ting[i][a[i][j-1]],0);
				link(ting[i][a[i][j-1]],ting[i][a[i][j]],0);
				//cout<<ting[i][a[i][j-1]]<<"sub"<<ting[i][a[i][j]]<<endl;;
			}		
			link(tai[a[i][j]],ting[i][a[i][j]],t[i][j]);
			link(ting[i][a[i][j]],tai[a[i][j]],t[i][j]);
			//cout<<a[i][j]<<"ting"<<ting[i][a[i][j]]<<"tai"<<tai[a[i][j]]<<endl; 
		}
	}
	for(int i=1;i<=op;i++){
		cin>>s[i].x>>s[i].y;
		s[i].id=i;
	}
	sort(&s[1],&s[op+1]);
	for(int i=1;i<=op;i++){
		//cout<<s[i].x<<","<<kou[s[i].y]<<endl;
		if(s[i].x!=s[i-1].x){
			init();
			dj(kou[s[i].x]);
		}
		ans[s[i].id]=dp[kou[s[i].y]];
		//cout<<dp[kou[s[i].y]]<<endl; 
	}	
	for(int i=1;i<=op;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
/*
考虑建图 
only 55
16:37打完暴力，已经<100pts了
哈哈哈哈哈哈哈哈哈哈哈哈哈 
A应该没有优解
B可以打，35分呢		t相同也还是要全图跑啊 没 
	 
	 
	 
	 
17:03 +了排序优化 



0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/

