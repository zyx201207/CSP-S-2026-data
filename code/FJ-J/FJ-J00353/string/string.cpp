#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200024];
char c[200024];
char s[100000024];
long long len=0;
long long l,r;
long long ans_f(){
	long long ans=0;
	l=1,r=len;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++,r--;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		for(int j = 1;j <= a[i];j++){
			s[++len]=c[i];
		}
	}
	cout << ans_f();
	return 0;
}
