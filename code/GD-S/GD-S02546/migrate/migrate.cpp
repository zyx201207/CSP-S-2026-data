#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+9;
int n,d,c,t;
int x[N];
int a[909][909];
int lis[909][909];
//bool vis[N];
/*
int dfs(u,v){
	if(u==v)return 1;
	for(int i=1;i<=n;i++){
		if(vis[])
	}
}

bool f(int u){
	int sum = 0;
	int minx = 1e9;
	for(int i=1;i<=n;i++){
		if(i == u) continue;
		vis[u] = 1;
		
	}
	
}
*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	
	
	while(t--){
		cin>>n>>d;
		memset(x,1e9,sizeof(x));
		memset(a,1e9,sizeof(a));
		memset(lis,0,sizeof(lis));
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			//a[i][i] = 0;
			for(int j=1;j<=n;j++){
				//if(a[i][j] != 1e9)continue;
				int l = abs(x[i]-x[j]);
				//cout<<l<<" ";
				if(l%d==0)a[i][j] = a[j][i] = l/d;
				else a[i][j] = a[j][i] = l/d + 1;				
			}
			//cout<<endl;
		}
		
		/*
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}cout<<endl;
		
		
		int ans = 0;
		for(int i=1;i<=n;i++){
			if(f(x))ans++;
		}
		*/
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				if(i==k)continue;
				for(int j=1;j<=n;j++){
					if(i==j||j==k)continue;
					int p = a[i][k] + a[k][j];
					if(p < a[i][j]){
						a[i][j] = a[j][i] = p;
						lis[i][j] = lis[j][i] = 0;
					}
					else if(p == a[i][j]){
						lis[i][j]++;lis[j][i]++; 
					}
				}
			}
		}
		int ans = 0;
		/*
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}cout<<endl;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<lis[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		*/
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(lis[i][j] == 4)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
