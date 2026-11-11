#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
	ll num = 0;
	char ch;
};

ll a[200010];
char ch[200010];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll n;
	scanf("%lld", &n);
	deque<Node> q;
	for(ll i=1; i<=n; i++){
		ll a1;
		char ch1;
		cin >> a1 >> ch1;
		q.push_back({a1, ch1});
	}
	
	ll ans = 0;
	while(!q.empty() ){
		Node first = q.front(), last = q.back();
		q.pop_front();
		q.pop_back();
		if(first.num > last.num){
			first.num -= last.num;
			if(first.ch != last.ch) ans += last.num;
			q.push_front(first);
		}else if(first.num < last.num){
			last.num -= first.num;
			if(first.ch != last.ch) ans += first.num;
			q.push_back(last);
		}else if(first.num == last.num){
			if(first.ch != last.ch) ans += first.num;
		}
		
		if(q.size() == 1) break;
	}
	
	printf("%lld", ans);
	
	return 0;
}
