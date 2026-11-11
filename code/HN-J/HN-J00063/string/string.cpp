#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll N=100005;
ll n,a,ans1=0,ans2=0;
char c;
string s[N],s1,s2;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> c;
		for(ll j=1;j<=a;j++){
			s[i] += c;
		}
		s1 += s[i];
	}
	s2 = s1;
	const ll &l1=s1.length();
	for(ll i=l1/2;i<l1;i++){
		if(s1[i] != s1[i - (l1 / 2)]){
			s1[i] = s1[i - (l1 / 2)];
			ans1++;
		}
	}
	const ll &l2=s2.length();
	for(ll i=0;i<l2/2;i++){
		if(s1[i] != s1[i + (l1 / 2)]){
			s1[i] = s1[i + (l1 / 2)];
			ans2++;
		}
	}
	cout << min(ans1, ans2) << endl;
	return 0;
}

