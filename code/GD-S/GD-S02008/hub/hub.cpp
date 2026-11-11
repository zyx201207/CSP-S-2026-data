#include <bits/stdc++.h>
#define ll long long
using namespace std;

int c,T,n,k,u,v,d[1100000],f[1100000];

vector<int> e[1100000];

void dfs(int u,int fa){
	f[u]=fa;
	
	for (int i=0; i<e[u].size(); i++){
		int v=e[u][i];
		
		if(v-fa){
			d[v]=d[u]+1;
			dfs(v,u);
		}
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
//	clock_t st=clock();
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> T;
	
	while(T--){
		cin >> n >> k;
		
		for (int i=1; i<n; i++) cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
		
		if(c==13||c==14){
			int m=n/2;
			
			if(k==n)  cout << "0\n";
			else if(k<n/2){
				cout<<(m+2-k+3)/4<<"\n";
			}
			else {
				cout << "1\n";
			}
		}
		else if(k==2){
			int ans=1e9+7,mx=0;
			for (int i=1; i<=n; i++){
				for (int j=1;j<=n; j++)  f[j]=j,d[j]=1e9+7;
				d[i]=0,f[i]=i;
				dfs(i,i);
				for (int j=1; j<=n; j++)mx=max(mx,d[j]);
				ans=min(ans,(mx+2)/3);
			}
			cout << ans << "\n";
		}
	}
	
//	clock_t endd=clock();
	
//	cout<<"time"<<1.0*(endd-st)/CLOCKS_PER_SEC;
	
	return 0;
}
