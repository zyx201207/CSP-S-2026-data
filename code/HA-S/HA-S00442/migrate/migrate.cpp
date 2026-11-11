#include<bits/stdc++.h>
using namespace std;
long long a[2000005],cnt[2000005];
vector<long long> v[100005],e;
int dfs(int x,int y,int t){
	if(x==y){
		cnt[t]++;
		e.push_back(t);
		return t;
	}
	if(x>y) return INT_MAX;
	int mn=INT_MAX;
	for(int i:v[x]){
		mn=min(dfs(i,y,t+1),mn);
	}
	return mn;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) v[i].push_back(j);
				else break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) continue;
				int a=dfs(i,j,0);
				if(a!=INT_MAX){
					if(cnt[a]==2) ans++;
				}
				for(int x:e){
					cnt[x]=0;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

