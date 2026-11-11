#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010];map<ll,ll>mp;
deque<ll>dq;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll k=1;k<=n;k++){
		for(ll i=k;i<=n;i++){
			ll c=a[i];bool f=0;
			for(auto t:dq)if(t==c){f=1;break;}
			if(f)while(dq.back()!=c)dq.pop_back();
			else dq.push_back(c);
		}
		while(!dq.empty()){
			mp[dq.back()]++;
			dq.pop_back();
		}
	}
	map<ll,ll>::iterator it;
	for(it=mp.begin();it!=mp.end();it++)cout<<it->second<<" ";
	return 0;
}
//EXP:48pts
