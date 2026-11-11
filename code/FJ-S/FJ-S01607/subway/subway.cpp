#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch==45)f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int c,n,m,d,q,mk;
int w[1000005];
int k[1000005];
struct node{
	int to,l;
};
vector<node> z[1000005];
int ll[1000005];
int a[505][505];
int dp[505][505];
int ans;
void floyd(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
	for(int k=1;k<=n;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
void f(){
//	cin>>c>>n>>m>>d>>q;
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
//		cin>>w[i];
		w[i]=read();
	}
//	cout<<"ok5";
	for(int i=1;i<=n;i++){
//		cin>>k[i];
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			int y;
			int l;
//			cin>>y>>l;
			y=read();
			l=read();
			z[y].push_back({i,l});
			ll[y]++;
		}
	}
//	cout<<"ok4";
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++){
		if(z[i].size()>=2){
			int len=ll[i];
			for(int x=0;x<len;x++){
				for(int y=0;y<len;y++){
					if(x==y)continue;
					int fr=z[i][x].to;
					int to=z[i][y].to;
					a[fr][to]=min(a[fr][to],z[i][x].l+z[i][y].l);
				}
			}
		mk=max(mk,ll[i]);
		}
	}
//	cout<<"ok3";
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=a[i][j];
		}
	}
//	cout<<"ok2";
//	cout<<mk<<"\n";
	for(int i=1;i<=n;i++)dp[i][i]=0;
	floyd();
//	cout<<"ok1";
	while(q--){
		int x,y;
//		cin>>x>>y;
		x=read();
		y=read();
		int l1=z[x].size();
		int l2=z[y].size();
		ans=1e18;
		for(int i=0;i<l1;i++){
			for(int j=0;j<l2;j++){
				int len=0;
				int fr=z[x][i].to;
				int to=z[y][j].to;
				len=w[x]+w[y];
				len+=z[x][i].l+z[y][j].l;
				len+=dp[fr][to];
				ans=min(ans,len);
//				cout<<fr<<" "<<to<<" : "<<len<<"-> "<<w[x]+w[y]<<" "<<z[x][i].l+z[y][j].l<<" "<<dp[fr][to]<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
}
signed main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	int t;
//	cin>>t;
//	while(t--)
	f();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
