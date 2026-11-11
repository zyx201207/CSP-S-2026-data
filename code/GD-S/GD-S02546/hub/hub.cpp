#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
const int N = 1009;
int a[N][N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u][v] = a[v][u] = 1;
		}
		
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
				}
			}
		}
		
		int ans = 1e9;
		
		for(int i=1;i<=n;i++){
			int d = -1;
			for(int j=1;i<=n;i++){
				d = max(d,a[i][j]);
			}
			int ans = min(ans,d);
		}
		cout<<ans<<endl;
	}	
	
	
	return 0;
} 
