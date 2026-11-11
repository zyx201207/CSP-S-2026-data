#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+5;
int n,a[N],ans,f=1;
long long l,s;
char c[N];
string s1,s2;
struct E{
	int l;
	char d;
};
vector<E>v[3];
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for ( int i = 1; i <= n;i++) {
		cin >> a[i] >> c[i];
		l+=a[i];
	}
	for ( int i = 1; i <= n;i++) {
		s+=a[i];
		if (s>(l+1)/2) {
			if (s-a[i]<=(l+1)/2) {
				if ((l/(ll)2)-(s-a[i]))v[1].push_back({(l/(ll)2)-(s-a[i]),c[i]});
				v[2].push_back({s-((l+1)/((ll)2)),c[i]});
			} else {
				v[2].push_back({a[i],c[i]});
			}
		} else {
			if (s==(l+1)/2&&(l&1)) {
				v[1].push_back({a[i]-1,c[i]});
			} else {
				v[1].push_back({a[i],c[i]});
			}
		}
	}
	for (auto x:v[1]) {
		for ( int i = 1; i <= x.l;i++) {
			s1 += x.d;
		}
	}
	for (auto x:v[2]) {
		for ( int i = 1; i <= x.l;i++) {
			s2 += x.d;
		}
	}
	for ( int i = 0; i < s1.size();i++) ans += (s1[i]!=s2[i]);
	cout << ans;
	return 0;
}
