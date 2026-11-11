#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a,sum;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		string t;
		scanf("%lld",&a);
		cin >> t;
		for(int i=1;i<=a;i++) s+=t;
	}
	int sz=s.size();
	for(int i=0;i<(int)sz/2;i++){
		if(s[i]!=s[sz-1-i]) sum++;
	}
	printf("%lld",sum);
	return 0;
}
