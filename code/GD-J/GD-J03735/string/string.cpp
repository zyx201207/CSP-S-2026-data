#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<ll,char>;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<P> s;
	s.push_back({0,' '});
	int cnt=0;
	for(int i=1;i<=n;i++){
		ll a;
		char c;
		cin >> a >> c;
		if(cnt==0){
			s.push_back({a,c});
			cnt++;
		}else{
			if(s[cnt].second == c) s[cnt].first+=a;
			else{
				s.push_back({a,c});
				cnt++;
			}
		}
	}
	ll ans=0;
	int l=1,r=cnt;
	while(l<r){
		if(s[l].first==s[r].first){
			if(s[l].second != s[r].second) ans+=s[l].first;
			l++;
			r--; 
		}else if(s[l].first>s[r].first){
			if(s[l].second != s[r].second) ans+=s[r].first;
			s[l].first-=s[r].first;
			r--;
		}else{
			if(s[l].second != s[r].second) ans+=s[l].first;
			s[r].first-=s[l].first;
			l++;
		}
	}cout << ans << '\n';
	return 0;
}
