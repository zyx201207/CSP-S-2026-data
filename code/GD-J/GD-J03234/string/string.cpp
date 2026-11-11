#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug(n) cout << #n << " = " << n << "\n";
#define deb(n) cout << #n << " = " << n << "    ";
#define div() cout << "\n---------------------\n";
#define dlog(n) cout << n;
int n;
struct node{
	int val,dis;char c;
}a[200005];
int tot;int ans;
int rpos;int now;int j;
inline void worksmall(){
	string s;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= a[i].val;j++){
			s += a[i].c;
		}
	}
	for(int i = 0;i < s.size();i++){
		if(i > s.size()-i-1){break;}
		if(s[i] != s[s.size()-i-1]){
			ans++;
		}
	}
	cout << ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].val >> a[i].c;
		a[i].dis = tot+1;tot += a[i].val;
	}
	if(tot <= 1000000){worksmall();return 0;}
	a[n+1].dis = tot+1;
	rpos = tot;j = n;
	for(int i = 1;i <= n;i++){
		if(j <= i){break;}
		now += a[i].val;
		int goal = tot-now+1;
		int delta = 0;
		while(j > i && a[j].dis >= goal){
			if(a[j].c != a[i].c){
				delta += (rpos-a[j].dis+1);
			}
			rpos = a[j].dis-1;
			j--;
		}
		if(j > i && a[j].c != a[i].c){
			delta += rpos-goal+1;
		}
		rpos = goal-1;
		ans += delta;
	}
	cout << ans;
	return 0;
}
