#include <bits/stdc++.h>
using namespace std;
const int N = 1e9;
long long n,a[N],k,l;
int main(){
	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
	string b,s;
	cin >> n;
	for(long long i = 0;i < n;i++){
		cin >> a[i] >> b[i];
		l += a[i];
	}
	if(n == 1){
		cout << '1';
		return 0;
	}
	for(long long i = 0;i < n;i++){
		for(long long j = k;j < k + a[i];j++){
			s[j] = b[i];
		}
		for(long long j = 0;j < a[i];j++) k++;
	}
	int le = 0,ri = l - 1,cnt = 0;
	while(le <= ri){
		if(s[le] != s[ri]){
			cnt++;
		}
		le++;
		ri--;
	}
	cout << cnt;
	return 0;
}
