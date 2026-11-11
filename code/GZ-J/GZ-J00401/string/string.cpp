//GZ-J00401 ³ÌÐÞÆë
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	vector<pair<ll,char>>a(n);
	for(auto &x:a)cin>>x.first>>x.second;
	ll l=0,r=n-1,ans=0;
	while(l<r){
		if(a[l].second!=a[r].second)ans+=min(a[l].first,a[r].first);
		if(a[l].first>a[r].first)a[l].first-=a[r--].first;
		else if(a[l].first<a[r].first)a[r].first-=a[l++].first;
		else l++,r++;
	}
	cout<<ans;
}
