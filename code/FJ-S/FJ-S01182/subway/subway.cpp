#include<bits/stdc++.h>
#include<vector>
#define ll long long
using namespace std;
const int N=505;
const int M=5e5+5;
const ll inf=1e18;
int c,n,m,d,q,w[M],K[M];
vector<int>a[N],t[N];
vector<int>o[M],T[M];
ll f[N][N];
int Read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while('0'<=ch&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)w[i]=Read();
	for(int i=1;i<=n;i++){
		K[i]=Read();
		for(int j=1;j<=K[i];j++){
			int aa=Read(),tt=Read();
			a[i].push_back(aa);
			t[i].push_back(tt);
			o[aa].push_back(i);
			T[aa].push_back(tt);
		}
	}
//	for(int i=1;i<=m;i++){
//		printf("%d:",i);
//		for(int j=0;j<o[i].size();j++)printf("%d ",o[i][j]);
//		puts("");
//	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		if(i==j)f[i][j]=0;
		else f[i][j]=inf;
	}
	for(int i=1;i<=m;i++){
		for(int x=0;x<o[i].size();x++)
			for(int y=x+1;y<o[i].size();y++){
				f[o[i][x]][o[i][y]]=min(f[o[i][x]][o[i][y]],(ll)T[i][x]+T[i][y]);
				f[o[i][y]][o[i][x]]=min(f[o[i][y]][o[i][x]],(ll)T[i][x]+T[i][y]);
			}		
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(q--){
		int x=Read(),y=Read();ll ans=inf;
		for(int i=0;i<o[x].size();i++){
			for(int j=0;j<o[y].size();j++){
				ans=min(ans,f[o[x][i]][o[y][j]]+T[x][i]+T[y][j]);
			}
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0; 
}
