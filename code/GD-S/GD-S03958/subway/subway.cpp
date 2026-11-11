#include<bits/stdc++.h>
using namespace std;

int w[55];
int c,n,m,d,q;
int sub[55][55];
int k[55][55];
int x[205];
int y[205];

struct Edge {
	int st[55];
	int sum=0;
	int subla;
	int ks=-1;	
}a[55];

int dp[55][55];
int ou[55];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	memset(sub,0,sizeof(sub));
	memset(k,0,sizeof(k));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		int ti;
		cin>>ti;
		for(int j=1;j<=ti;j++){
			cin>>sub[i][j];
			cin>>k[i][j];
			a[sub[i][j]].subla=sub[i][j-1];
			a[sub[i][j]].ks=k[i][j];
			a[sub[i][j-1]].st[a[sub[i][j]].sum]=(sub[i][j]);
			a[sub[i][j]].sum++;
		}
	}
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=55;i++){
		dp[i][i]=0;
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		int tot=0;
		tot+=w[x[i]]+w[y[i]];
		int zz=1e5;
		int jj=y[i];
		do{
			int gg;
			int ff;
			for(int j=1;j<=a[y[i]].sum;j++){
				ff=jj;
				zz=a[jj].st[j];
				dp[jj][zz]=min(dp[jj][zz],a[zz].ks);
				gg=min(gg,dp[jj][zz]);
				ff=zz;
			}
			tot+=gg;
			jj=ff;
		}while(zz!=1);
		ou[i]=tot;
	}
	for(int i=1;i<=q;i++){
		cout<<ou[i]<<endl;
	}
	return 0;
}
