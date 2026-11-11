#include<bits/stdc++.h>
using namespace std;
long long a[200010],tot,k,vis[200010],ans,tb,n,m,vb;
bool mar=0;
vector<int>w[50];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
	
	cin>>n>>m;
	ans=(1ULL<<40)-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tb=a[i];
		tot=0;
		while(tb){ 
			if(tb&1)w[tot].push_back(i);
			tb>>=1;
			tot++;
		}
	}
	for(int i=40;i>=0;i--){
		vb=w[i].size();
		if(vb>=m){
			tot=0;
			for(int j:w[i]){
				if(vis[j]==k){
					tot++;
				}
			}
			if(tot<m)continue;
			for(int j:w[i]){
				if(vis[j]==k)vis[j]++;
			}
			k++;
		}
	}
	tot=1;
	for(int i=1;i<=n&&tot<=m;i++){
		if(vis[i]==k){
			tot++;
			ans=(ans&a[i]);
		}
	}
	if(tot<=m)cout<<0;
	else cout<<ans;
	
	return 0;
} 
