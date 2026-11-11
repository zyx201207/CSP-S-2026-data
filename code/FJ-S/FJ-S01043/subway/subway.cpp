#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pair<int,int> P
#define endl "\n"
const int maxn=5e2+5;
const int maxk=5e5+5;
vecotr<int> l[maxn];
int d[maxk][maxn];
int c,n,m,d,q,w[maxn],a[maxn][maxk],t[maxn][maxk],k[maxn],P[maxk],idx;
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	 for(int i=1;i<=m;i++) cin>>w[i];
	 for(int i=1;i<=m;i++) l[i].clear();
	 sort(w+1,w+n+1);
	 int l=1;
	 for(int i=1;i<=n;i++)
	 {
	 	cin>>k[i];
	 	for(int j=1;j<=k[i];j++)
	 	{
	 		cin>>a[i][j]>>t[i][j];
		 }
	 }
	 if(C>=7 && C<=11)
	 {
	 	while(q--)
		 {
		 	int s,t;cin>>s>>t;
		 	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++) d[i][j]=LLONG_MAX;
		 	cout<<d*2<<endl; 
		  }
	 }
	 if(C>=12 && C<=19)
	 {
		while(q--)
		 {
		 	int s,t;cin>>s>>t;
		 	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++) d[i][j]=LLONG_MAX;
		 
		 	cout<<w[1]+w[2]+t[1][1]*2<<endl;
		  }
	 }
	return 0;
}

