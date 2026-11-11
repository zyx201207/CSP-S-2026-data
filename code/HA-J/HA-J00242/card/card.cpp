#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
map<int,int> mp;
map<int,int> ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(auto &j:mp){
			if(j.second%2==1) ans[j.first]++;
		}
		mp[a[i]]--;
	}
	for(auto &i:ans) cout<<i.second<<' ';
	return 0;
}
