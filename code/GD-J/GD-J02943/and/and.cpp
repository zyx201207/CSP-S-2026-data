#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
#define int long long
int n,m;
int a[N],ans;
vector<pair<int,int>>dp;
void solve1(){
	if(m == 1){
		for(int i = 1;i <= n;i ++)ans = max(ans,a[i]);
		cout << ans;
		return;
	}
	if(m == n){
		ans = a[1];
		for(int i = 2;i <= n;i ++)ans = ans&a[i];
		cout << ans;
		return;
	}
	for(int i = 1;i <= n;i ++){
		for(auto t : dp){
			if(t.second+1 == m){
				ans = max(ans,t.first&a[i]);
			}
			else dp.push_back({t.first&a[i],t.second+1});
		}
		dp.push_back({a[i],1});
	}
	cout << ans;	
}
string tot(int a){
	string s = "";
	for(int i = 0;i <= 30;i ++){
		if(a&(1<<i))s="1"+s;
		else s="0"+s;
	}
	return s;
}
string s[N];
bool tg[N];
void solve2(){
	for(int i = 1;i <= n;i ++){
		s[i] = tot(a[i]);
	}
	int q = 0;
	for(int i = 0;i <= 30;i ++){
		int cnt = 0;
		for(int j = 1;j <= n;j ++){
			if(s[j][i] == '1'){
				cnt++;
				tg[j] = 1;
			}
		}
		if(cnt >= m){
			q = i;
			break;
		}
	}
	ans += (1<<(30-q));
	for(int i = q+1;i <= 30;i ++){
		int cnt = 0;
		for(int j = 1;j <= n;j ++){
			if(tg[j]&&s[j][i] == '1'){
				cnt++;
			}
		}
		if(cnt >= m){
			for(int j = 1;j <= n;j ++){
				if(tg[j]&&s[j][i] == '0'){
					tg[j] = 0;
				}
			}
			ans += (1<<(30-i));
		}
	}
	cout << ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)cin >> a[i];
	if(n <= 2000) solve1();
	else solve2();
	return 0;
}
