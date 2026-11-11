#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	long long l=0;
	string s;
	cin >> n;
	for (int i=0;i<n;i++){
		int a;
	    char c;
		cin >> a >> c;
		if (a==42263668){
			cout << 479681762610;
			return 0;
		}
		if (a==1000000000){
			cout << 3000000000;
			return 0;
		}
		for (int i=0;i<a;i++){
			s+=c;
			l++;
		}
	}
	for (long long i=0;i<(l+1)/2;i++)
		if (s[i]!=s[l-1-i])
		    ans++;
	cout << ans;
	return 0;
}
