#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
using namespace std;
deque<pair<ll,char> > q;
ll a[200005];
char c[200005];
int main(){
	int n;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		q.push_back({a[i],c[i]});
	}
	ll ans=0;
	while(q.size()>1){
		ll frt=q.front().fir,bck=q.back().fir;
		char c1=q.front().sec,c2=q.back().sec;
		if(frt>bck){
			q.pop_front();
			q.push_front({frt-bck,c1});
			q.pop_back();
		}
		else if(frt<bck){
			q.pop_front();
			q.pop_back();
			q.push_back({bck-frt,c2});
		}
		else{
			q.pop_front();
			q.pop_back();
		}
		if(c1!=c2) ans+=min(frt,bck);
	}
	cout << ans << '\n'; 
	return 0;
} 
