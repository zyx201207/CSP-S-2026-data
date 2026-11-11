#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
long long c,t,n,d,a[maxn],dis[maxn][maxn],p[maxn][maxn];
int main(){
	ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		fill_n(dis[0],n*maxn,2e9);
		fill_n(p[0],n*maxn,0);
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
			int j=i+1;
			while(a[j]-a[i]<=d)dis[i][j]=1,p[i][j++]=1;
		}
		for(int k=2;k<n;k++){
			for(int i=1;i<k;i++)for(int j=k+1;j<=n;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j])dis[i][j]=dis[i][k]+dis[k][j],p[i][j]=p[i][k]*p[k][j];
				else if(dis[i][j]==dis[i][k]+dis[k][j])p[i][j]++;
			}
		}
		for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++){
			if(p[i][j]==2)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
