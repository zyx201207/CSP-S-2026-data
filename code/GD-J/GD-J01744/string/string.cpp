#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Len = 2e5 + 5;
long long a[Len];
long long N;
long long ans;
char s[Len];
int n;

vector <pair<long long, char>> S;
int l;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	cin >> a[0] >> s[0];
	for (int i=1;i<n;i++) {
		cin >> a[i] >> s[i];
		if (s[i] == s[i-1])
			a[i] += a[i-1];
		else {
			l++;
			S.push_back({a[i-1], s[i-1]});
		}
		N += a[i];
	}
	S.push_back({a[n-1], s[n-1]}); 
	
//	for (int i=0;i<=l;i++) {
//		for (int j=0;j<S[i].first;j++) {
//			cout << S[i].second;
//		}
//	}
//	cout << "\n";
	
	int st = 0, ed = l;
	long long L = 0, R = N-1;
	long long cnt = 0;
	while (st < ed) {
		long long nums = S[st].first, nume = S[ed].first;
//		cout << st << " " << ed << "\n"; 
//		cout << L << " " << R << "\n"; 
		if (nums == nume)  {
			if (S[st].second == S[ed].second) {
				st++;
				ed--;
			}			
			else {
				ans += nums;
				st++;
				ed--;
			}
			L += nums;
			R -= nume;			
		}		
		else if (S[st].second == S[ed].second) {
			if (nums > nume) {
				L += nume;
				R -= nume;
				cnt = nums - nume;
				S[st].first = cnt;				
				ed--;
			}
			else {
				L += nums;
				R -= nums;
				cnt = nume - nums;
				S[ed].first = cnt;				
				st++;
			}			
		}
		else {
			if (nums > nume) {
				L += nume;
				R -= nume;
				ans += nume;
				cnt = nums - nume;
				S[st].first = cnt;				
				ed--;
			}
			else {
				L += nums;
				R -= nums;
				ans += nums;
				cnt = nume - nums;
				S[ed].first = cnt;				
				st++;
			}
		}
//		cout << ans << "\n";
	}
	
	cout << ans << "\n";
	return 0;
}
