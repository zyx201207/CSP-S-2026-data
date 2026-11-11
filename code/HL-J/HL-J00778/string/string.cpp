#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll num;
	char c ;
};
ll ans,n;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	deque<node>q;
	cin >> n;
	for(int i = 1;i <= n;i ++) {
		char s;int tmp;
		cin >> tmp >> s;
		q.push_front({tmp , s});
	}
	while(q.size() > 1){
		auto [ftmp , fs] = q.front();
		q.pop_front();
		auto [btmp , bs] = q.back();
		q.pop_back();
		if(fs == bs){
			if(ftmp == btmp) continue;
			else if(ftmp > btmp){
				ftmp -= btmp;
				q.push_front({ftmp , fs});
			}else{
				btmp -= ftmp;
				q.push_back({btmp , bs});
			}
		}else{
			if(ftmp == btmp){
				ans += ftmp;
			}else if(ftmp > btmp){
				ftmp -= btmp;
				ans += btmp;
				q.push_front({ftmp , fs});
			}else{
				btmp -= ftmp;
				ans += ftmp;
				q.push_back({btmp , bs});
			}
		}
	}
	cout << ans;
	return 0;
}