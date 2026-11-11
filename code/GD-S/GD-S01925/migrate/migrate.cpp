#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5005;
int c,t,n,d,x[N],cnt[N][N];
__int128 dist[N][N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>c>>t;
	
	while(t--){
		cin>>n>>d;
		
		if(n>5000){
			cout<<"0\n";
			continue;
		}
		
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j)dist[i][j]=0;
			else dist[i][j]=2e18;
		}
		
		int last=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			while(last<i&&x[last]+d<x[i])last++;
			for(int j=last;j<i;j++)
			dist[j][i]=dist[i][j]=1;
		}
		
		for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(i!=j&&j!=k&&i!=k){
			if(dist[i][j]==dist[i][k]+dist[k][j])
				cnt[i][j]++;
			else if(dist[i][j]>dist[i][k]+dist[k][j]){
				dist[i][j]=dist[i][k]+dist[k][j];
				cnt[i][j]=1;
			}
		}
		
		int ans=0;
		
		for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)	
		if(cnt[i][j]==2)ans++;
		
		cout<<ans<<'\n';
	}
	
	return 0;
}
