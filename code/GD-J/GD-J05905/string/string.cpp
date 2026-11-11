#include <bits/stdc++.h>
using namespace std;

string s;
long long ans;
int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int nn = n;
	if (n==1) {
		int a;char c;
		cin >> a >> c;
		cout << 0;
		return 0;
	}
	if (n==2){
		int a,a1;
		char c,c1;
		cin >> a >> c >> a1 >> c1;
		if (c==c1){
			cout << 0;
			return 0;
		}
		cout << min(a,a1);
		return 0;
	}
	while (nn--){
		long long a;char c;
		cin >> a >> c;
		string s1;
		s1+=c;
		while (s1.size()<=a/2){
			s1+=s1;			
		}
		if (s1.size() < a)for (int i=s1.size();i<a;i++) s1+=c;
//		cout << s1 << '\n';
//		cout << s1.size();
		s+=s1;
	}
//	cout << s.size();
//	cout << s << '\n';
	long long num = s.size();
	long long sum = s.size()/2;
	for (long long i=0;i<sum;i++){
		if (s[i]!=s[num-i-1])ans++;
	}
	cout << ans;
	return 0;
}
