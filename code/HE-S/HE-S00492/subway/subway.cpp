#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
const long long inf=0x3f3f3f3f3f3f3f3fll;
int c,n,m,d,q;
long long w[M];
int fst[M],nxt[M],tot,a[M];
long long t[M];
long long f[N][N];
inline void add(int x,int i,int y){
	a[++tot]=i;t[tot]=y;
	nxt[tot]=fst[x];
	fst[x]=tot;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1,k;i<=n;i++){
		cin>>k;
		for (int j=0,x,y;j<k;j++){
			cin>>x>>y;
			add(x,i,y);
		}
	}
	memset(f,0x3f,sizeof(f));
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int i=1;i<=m;i++)
		for (int l=fst[i];l;l=nxt[l])
			for (int r=fst[i];r;r=nxt[r])
				f[a[l]][a[r]]=min(f[a[l]][a[r]],t[l]+t[r]);
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while (q--){
		int x,y;cin>>x>>y;
		long long ans=inf;
		for (int l=fst[x];l;l=nxt[l])
			for (int r=fst[y];r;r=nxt[r])
				ans=min(ans,f[a[l]][a[r]]+t[l]+t[r]);
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}

/*
为什么 d 要开 20 啊！！！

求你了 CCF，T2 让我 O(n^3+(m+q)*d^2)=O(3.65e8) 的复杂度过吧！/ll 

哎？好像复杂度真了？O(n^3+Σk*d+q*d^2)？ 
*/
