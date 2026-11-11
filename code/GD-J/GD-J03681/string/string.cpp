#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<pair<int,char>> mp;
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	mp.resize(n+1);
	for(int i=1;i<=n;i++)
		cin>>mp[i].first>>mp[i].second;
	int i=1,j=n;
	while(i<j){
		int sz=min(mp[i].first,mp[j].first);
		if(mp[i].second!=mp[j].second)
			ans+=sz;
		mp[i].first-=sz;
		mp[j].first-=sz;
		if(!mp[i].first)
			i++;
		if(!mp[j].first)
			j--;
	}
	cout<<ans;
	return 0;
}

