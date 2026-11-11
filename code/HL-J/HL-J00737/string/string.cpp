#include <bits/stdc++.h>

using ll = long long ;

ll n;

std::string s;

int main(){
	
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	
	std::cin>>n;
	
	while (n--){
		ll a;
		char c;
		std::cin>>a;
		std::cin>>c;
		while (a--)
			s += c;
	}
	
	ll ans = 0;
	
	bool isJi = (s.size()%2==1 ? true : false);
	
	if (isJi){
		for (ll i=0 ; i<(s.size()-1)/2 ; ++i)
			if (s[i] != s[s.size()-i-1])
				++ans;
		std::cout<<ans;
		return 0;
	}
	
	ans = 0;
	if (!isJi) {
		for (ll i=0 ; i<s.size()/2 ; ++i)
			if (s[i] != s[s.size()-i-1])
				++ans;
		std::cout<<ans;
		return 0;
	}

	return 0;
	
}
