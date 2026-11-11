#include<bits/stdc++.h>
using namespace std;
int c,t;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		vector<int> num[1005];
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,k;
			cin>>u>>k;
			num[u].push_back(k);
			num[k].push_back(u);
		}
		bool cnt[10005]={0};
		queue<int> nu;
		nu.push(1);
		int ans=1;
		while(nu.size()!=0){
			int nown=nu.front();
			nu.pop();
			if(cnt[nown]==1) {
				continue;
			}
			else {
				cnt[nown]=1;
				for(auto i:num[nown]){
					nu.push(i);
				}
				ans++;
			}
		}
		cout<<max(n-ans,1);
	}
	return 0;
}