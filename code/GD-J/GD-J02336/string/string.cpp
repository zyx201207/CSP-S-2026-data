#include<bits/stdc++.h>
using namespace std;
using ll=long long;

deque<ll>a;
deque<char>c;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		ll x;char y;
		cin>>x>>y;
		a.push_back(x);
		c.push_back(y);
	}
	ll ans=0;
	while(!a.empty()){
		if(c.front()!=c.back()){
			if(a.front()>a.back()){
				ans+=a.back();
				ll x=a.front();
				a.pop_front();
				a.push_front(x-a.back());
				c.pop_back();
				a.pop_back();
			}
			else{
				ans+=a.front();
				ll x=a.back();
				a.pop_back();
				a.push_back(x-a.front());
				c.pop_front();
				a.pop_front();
			}
		}
		else{
			if(a.front()>a.back()){
				ll x=a.front();
				a.pop_front();
				a.push_front(x-a.back());
				c.pop_back();
				a.pop_back();
			}
			else{
				ll x=a.back();
				a.pop_back();
				a.push_back(x-a.front());
				c.pop_front();
				a.pop_front();
			}
		}
		
	}
	cout<<ans;
	return 0;
}
