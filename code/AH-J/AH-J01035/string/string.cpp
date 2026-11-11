#include <bits/stdc++.h>
using namespace std;
using LL=long long;
LL n,ans;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	while(n--){
		LL a;char c;
		cin>>a>>c;
		while(a--) s+=c;
	}
	LL len=s.size();
	for(LL i=0;i<len/2;i++) if(s[i]!=s[len-i-1]) ans++;
	printf("%lld",ans);
	return 0;
}
