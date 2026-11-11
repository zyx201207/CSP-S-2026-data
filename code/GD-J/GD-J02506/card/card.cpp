#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int ans[300010];
bool mp[300010];
deque<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		q.clear();
		for(int x=0;x<=m+3;x++){
			mp[x]=false;
		}
		for(int j=i;j<=n;j++){
			if(mp[a[j]]){
				for(auto x:q){
					mp[x]=false;
				}
				q.clear();
				q.push_back(a[j]);
				mp[a[j]]=true;
			}else{
				q.push_back(a[j]);
				mp[a[j]]=true;
			}
		}
		for(auto x:q){
			if(mp[x]){
				ans[x]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
