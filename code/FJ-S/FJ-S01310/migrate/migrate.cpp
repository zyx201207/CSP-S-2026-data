#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0; char ch; bool f=0;
	while(((ch=getchar())<'0'||ch>'9')&&ch!='-') ;
	if(ch=='-') f=1;
	else x=(ch^48);
	while((ch=getchar())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x; 
}
bool st1;
const int N=2e6+55;
int n;
ll a[N],m;
int nex[N],lst[N]; 
ll va[N][5],v2[N][5],g[5];
int s1[N],s2[N],s3[N];
int qur(int l,int r,int v){
	if(l>r) return 0;
	if(v==l-2) return s2[l];
	return s1[l];
	int L=l,R=r;
	while(L<=R){
		int mid=(L+R)/2;
		if(lst[mid]<v) L=mid+1;
		else R=mid-1;
	}
	int pl=L;
	L=l,R=r;
	while(L<=R){
		int mid=(L+R)/2;
		if(lst[mid]<=v) L=mid+1;
		else R=mid-1;
	}
	int pr=L-1;
	if(pl<=pr) return pr-pl+1;
	else return 0;
}
void solve(){
	n=read(),m=read();
	for(int i=0;i<=n+1;i++){
		va[i][0]=va[i][1]=0;
		v2[i][0]=v2[i][1]=0;
		s1[i]=s2[i]=s3[i]=0;
	}
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1,j=1;i<=n;i++){
		while(j<=i&&a[i]-a[j]>m) j++;
		lst[i]=j;
	}
	for(int i=n,j=n;i>=1;i--){
		while(j>=i&&a[j]-a[i]>m) j--;
		nex[i]=j;
	}
	lst[1]=0;
	for(int i=n;i>=1;i--){
		s3[lst[i]]++;
		//i==l+1,l==i-1
		s1[i]=s3[i-1];
		if(i>=3) s2[i]=s3[i-2];
	}
	ll ans=0;
	for(int x=n;x>=1;x--){
		int c=0;
		int p1=-1,p2=-1,p3=-1,p4=-1,p5=-1,p6=-1;
		int cnt=0,tc=0;
		for(int y=x;y<=n;p6=p5,p5=p4,p4=p3,p3=p2,p2=p1,p1=y,y=nex[y]){
			if(nex[y]==y) break;
			if(p6!=-1){
//				cerr<<p6<<","<<p5<<","<<p4<<","<<p3<<","<<p2<<","<<p1<<": "<<y<<"??"<<x<<"!!\n";
				for(int i=0;i<2;i++){
					va[x][c+i]+=v2[p4][i];
				}
				break;
			}
			int t1=max(lst[y],x);
			int l=y,r=nex[y];
			r=max(r,l);
			if(p1!=-1&&t1!=p1) c++;
			if(t1<p1-1) c++;
			if(p2!=-1&&max(lst[t1],x)!=p2&&t1!=p1) c++;
			if(c>1) break;
			if(y==x) continue;
			g[0]=va[x][0];
			g[1]=va[x][1];
			va[x][c]+=qur(l+1,r,l);
			if(max(lst[l-1],x)>=p1){
				va[x][c+1]+=qur(l+1,r,l-1);
			}
		}
		p1=-1,p2=-1,p3=-1,p4=-1,p5=-1;
		p4=x,p3=nex[p4],p2=nex[p3],p1=nex[p2];
		if(nex[p1]!=p1){
			c=0;
//			cout<<x<<","<<nex[p1]<<"!!\n";
			for(int y=nex[p1];y<=n;p6=p5,p5=p4,p4=p3,p3=p2,p2=p1,p1=y,y=nex[y]){
				if(nex[y]==y) break;
				int t1=max(lst[y],x);
				int l=y,r=nex[y];
				r=max(r,l);
				if(p1!=-1&&t1!=p1) c++;
				if(t1<p1-1) c++;
				if(p2!=-1&&max(lst[t1],x)!=p2&&t1!=p1) c++;
				if(c>1) break;
				if(y==x) continue;
				v2[x][c]+=qur(l+1,r,l);
				if(max(lst[l-1],x)>=p1){
					v2[x][c+1]+=qur(l+1,r,l-1);
				}
//				y=nex[y];
				for(int i=0;i<2;i++){
					v2[x][c+i]+=v2[nex[x]][i];
				}
				break;
			}
		}
//		for(int c=0;c<2;c++){
//			cout<<va[x][c]<<" ";
//		}puts("");
	}
	for(int x=1;x<=n;x++){
		ans=ans+va[x][1];
	}
	printf("%lld\n",ans);
}
bool st2;
int main(){
//	cout<<(&st1-&st2)/1024/1024; return 0;
//	system("fc migrate6.ans migrate.out"); return 0;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read();
	int T=read();
	while(T--) solve();
	return 0;
}
/*
migrate
问题：
求出多少对(x,y),使得有恰好两条最短路
每次可以走距离 <= d 的 
分析一下，肯定走的是递增的，否则可以少走一步 
每个点的后继唯一
形 
----------------------------------
x一直跳，
-------------------------
nex[i]表示i往后最远的，形成一棵树T1
lst[i]表示i往前最远的，形成一棵树T2
把x到y T1上的路径拿出来
y到x T2上的路径拿出来 
如果上面的点，
*/
