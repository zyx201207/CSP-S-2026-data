#include <bits/stdc++.h>
using namespace std;
long long n,sum,ans;
string s="";
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long a[n];
	char b[n];
	for(int i = 0;i < n;i++){
		cin >> a[i] >> b[i];
		sum+=a[i];
		for(int j = 0;j < a[i];j++){
			s+=b[i];
		}
	}
	for(int i = 0;i < (sum/2+1);i++){
	    if(s[i]!=s[sum-i])ans++;
	}
	cout << ans;
	return 0;
}
