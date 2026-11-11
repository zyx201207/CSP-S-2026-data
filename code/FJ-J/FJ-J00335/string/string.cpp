#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
struct node{
	long long a;
	char c;
}x[N];
deque<node> dq;
unsigned long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> x[i].a >> x[i].c;
		dq.push_back(x[i]);
	}
	while (!dq.empty()){
		if (dq.size() == 1){
			break;
		}
		node t = dq.front(),w = dq.back();
		// cout << t.c << " " << w.c << "\n";
		int mn = min(t.a,w.a);
		if (t.c != w.c){
			ans += mn;
		}
		dq.front().a -= mn;
		dq.back().a -= mn;
		if (t.a == 0){
			dq.pop_front();
		}
		if (w.a == 0){
			dq.pop_back();
		}
		// dq.pop_front(),dq.pop_back();
	}
	cout << ans;
	return 0; 
}
