
#include <bits/stdc++.h>
using namespace std;
int n,ans;
char s[20000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("sting.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		long long a;
		char c;
		scanf("%lld%c",&a,&c);
		for (int j = 1;j <= a;i++)
			s[j] = c;
	}
	long long l = strlen(s+1);
	for (int i = 1;i <= l;i++){
		if (s[i] != s[l-i+1])
			ans++;
	}
	printf("%d",ans);
	return 0;
}
