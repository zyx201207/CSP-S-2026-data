#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 10;
char s[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long qw;
	cin>>qw;
	long long n = qw;
	long long num;
	while(qw--){
		int a;
		char c;
		cin>>a>>c;
		for(long long j = num;j < num + a;j++){
			s[j] = c;
		}
		num += a;
	}
	if(n <= 1){
		cout<<0;
		return 0;
	}
	long long left = 0, right = num - 1;
	long long sum = 0;
	while(left <= right){
		if(s[left] != s[right]){
			sum++;
		}
		left++;
		right--;
	}
	cout<<sum;
	return 0;
}
