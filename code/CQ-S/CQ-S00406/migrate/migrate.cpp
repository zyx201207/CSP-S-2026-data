#include<bits/stdc++.h>
#define int long long
using namespace std;

int cc,T;
int n,d;
int a[5010];
vector<int> v[5010];
struct o{
	int x,b;
};

queue<o> q;
int ans;

signed main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>cc>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) v[i].push_back(j);
			}
		}
		
		for(int i=1;i<=n;i++){
			q.push({i,0});
			int dp[5010]={0};
			int f[5010]={0};
			for(int j=i+1;j<=n;j++) f[j]=1e9;
			while(q.size()){
				int x=q.front().x,z=q.front().b;
				q.pop();
				for(int j=0;j<v[x].size();j++){
					int y=v[x][j];
					if(f[y]>z+1){
						f[y]=z+1;
						dp[y]=1;
					}
					else if(f[y]==z+1){
						dp[y]++;
					}
					if(f[y]-1>z+1) continue;
					q.push({y,z+1});
				}
			} 
			for(int j=i+1;j<=n;j++){
				if(dp[j]==2) ans++;
			}
		}	
		cout<<ans<<endl;
	}
		
	return 0;
} 
