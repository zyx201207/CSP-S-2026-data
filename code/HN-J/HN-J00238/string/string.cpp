#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
struct P {
	ll len;
	char c;
};
P s[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	ll sum = 0 ;
	for(int i=1 ; i<=n ; i++) {
		cin>>s[i].len>>s[i].c;
		sum += s[i].len;
	}
	sum /= 2;
//	cout<<sum<"\n";
	int l =1 , r = n;
	ll cnt = 0;
	while(l<r) {
		if(s[l].c == s[r].c) {
			if(s[l].len >= s[r].len) {
				s[l].len -= s[r].len;
				s[r].len = 0;
			} else {
				s[r].len -= s[l].len;
				s[l].len = 0;
			}
		} else {
			if(s[l].len >= s[r].len) {
				if(cnt + s[r].len >= sum) {
					cout<<sum;
					return 0;
				}
				cnt += s[r].len;
				s[l].len -= s[r].len;
				s[r].len = 0;
			} else {
				if(cnt + s[l].len >= sum) {
					cout<<sum;
					return 0;
				}
				cnt += s[l].len;
				s[r].len -= s[l].len;
				s[l].len = 0;
			}
		}
		if(s[l].len == 0) l++;
		if(s[r].len == 0) r--;
	}
	cout<<cnt;
	return 0;
}

















