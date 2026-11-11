#include<bits/stdc++.h>
using namespace std;
deque<int> q;
map<int,bool> mp;
int n,a[500005],ans[200005],i,j,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(i=l;i<=n;i++){
			if(mp[a[i]]==0){
				q.push_back(a[i]);
				mp[a[i]]=1;
			}
			else{
				while(!q.empty()&&q.back()!=a[i]){
					mp[q.back()]=0;
					q.pop_back();
				}
			}
		}
		for(i=1;i<=m;i++){
			ans[i]+=mp[i];
			mp[i]=0;
		}
	}
	for(i=1;i<=m;i++) cout<<ans[i]<<" ";
}
