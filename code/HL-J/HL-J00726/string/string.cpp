#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
int n;
struct charr{
	int a;
	char c;
};
struct charsum{
	int l,r;
	char c;
};
int len;
vector<charr> vec;
string str;

inline int solve(){
	int cnt = 0;
	for(int i = 1;i <= (str.size() + 1) / 2;i++)
	{
		if(str[i-1] != str[str.size()-i]){
			cnt++;
		}
	}
	return cnt;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> n;
	
	char lc = ' ',now = 1;
	for(int i = 1;i <= n;i++)
	{	
		if(lc == cc){
			vec.back().a += aa;
		}
		else{
			vec.push_back({aa,cc});
		}
		lc = cc;
		while(aa){
			str += cc,aa--;
		}
	}
	
	cout << solve() << '\n';
	
	return 0;
}