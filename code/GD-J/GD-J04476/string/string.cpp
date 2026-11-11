#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
deque<pair<ll,char>> q;
int n;
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;char c;
		cin>>x>>c;
		if(q.front().second==c){
			x+=q.front().first;
			q.pop_front();
		}
		q.push_front({x,c});
	}
	while(q.size()>1){
		ll x1=q.front().first;
		char c1=q.front().second;
		ll x2=q.back().first;
		char c2=q.back().second;
		q.pop_front();
		q.pop_back();
		if(x1==x2){
			if(c1!=c2) ans+=x1;
			continue;
		}
		ll nx=abs(x1-x2);
		if(x1>x2){
			q.push_front({nx,c1});
			if(c1!=c2){
				ans+=x2;
			}
		}else{
			q.push_back({nx,c2});
			if(c1!=c2){
				ans+=x1;
			}
		}
		
		
	}
	cout<<ans<<"\n";
	return 0;
}

