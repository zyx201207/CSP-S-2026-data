#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005];
int ans[300005];
map<int,int>mp;
queue<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		mp.clear();
		for(int j=i;j<=n;j++){
			if(mp.count(a[j])){
				for(auto it:mp){
					if(it.second>mp[a[j]]){
						q.push(it.first);
					}
				}
				while(!q.empty()){
					mp.erase(q.front());
					q.pop();
				}
			}else{
				mp[a[j]]=mp.size()+1;
			}
		}
		for(auto it:mp) ans[it.first]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
