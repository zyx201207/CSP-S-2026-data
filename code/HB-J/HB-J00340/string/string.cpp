#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt;
	cin >> n;
	long long a[n];
	string S,c[n];
	for (long long i = 0;i<n;i++){
		cin >> a[i] >> c[i];
		for (long long j = 0;j<a[i];j++){
			S += c[i];
		}
	}
	long long l = S.size();
	cnt = l/2;
	if (l%2==1){
		for (long long i = l/2+1;i<l;i++){
			if (S[i] == S[l-i-1]){
				cnt--;
			}
		}
	}else{
		for (long long i = l/2;i<l;i++){
			if (S[i] == S[l-i-1]){
				cnt--;
			}
		}
	}
	cout << cnt;
	return 0;
}
