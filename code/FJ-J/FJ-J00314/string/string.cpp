#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
long long a[N];
char aa[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	scanf("%d", &n);
	string s;
	while(n--){
		long long x;
		char c;
		cin >> x >> c;
		for(int i = 1; i <= x; i++) s += c;
	}string ss = s;
	reverse(s.begin(), s.end());
	//cout << s << "\n" << ss << "\n";
	long long len = s.size();
	long long bt = 0;
	for(int i = 0; i < len; i++){
		if(s[i] != ss[i]){
			bt++;
			//cout << i << " ";
		}
	}//cout << "\n";
	printf("%lld", bt/2);	
//	for(int i = 1; i <= n; i++) cin >> a[i] >> aa[i];
//	long long l = 1, r = n, bt = 0;
//  long long asn = 0;
//	while(l < r){
//		if(aa[l] != aa[r]){
//			if(aa[l] < 
//		}
//	}
	return 0;
}
