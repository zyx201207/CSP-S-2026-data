#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[2000005];
vector<int>e[2000005];
int de[2000005];
int cnt[2000005];
void dfs(int u){
	for(int v:e[u]){
		if(de[v]>de[u]+1){
			de[v]=de[u]+1;
			cnt[v]=1;
			dfs(v);
		}
		else if(de[v]==de[u]+1){
			cnt[v]+=1;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			e[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			int s=i;
			memset(cnt,0,sizeof(cnt));
			memset(de,0x3f,sizeof(de));
			de[s]=0;
			cnt[s]=0;
			dfs(s);
			for(int j=1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		ans/=2;
		cout<<ans<<"\n";
	}
	return 0;
} 
