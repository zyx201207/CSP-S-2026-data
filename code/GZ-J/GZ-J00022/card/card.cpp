//GZ-J00022,商梓辰，贵阳市第三中学
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;cin>>n>>m;
	vector<ll>cnt(m+1,0);
	vector<ll>a(n+1,0);
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}	
	for(ll i=1;i<=n;i++){
		map<ll,ll>mp;
		deque<ll>q; 
		for(ll j=i;j<=n;j++){
			if(mp[a[j]]>0){  
				for(ll k=mp[a[j]];k<j;k++){
					mp[q.back()]=0;
					q.pop_back();
				}
			}
			q.push_back(a[j]);
			mp[a[j]]=j;
			
		} 
		for(ll j=0;j<(ll)q.size();j++){
			cnt[q[j]]++;
		} 
	}
	for(ll i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;

} 

