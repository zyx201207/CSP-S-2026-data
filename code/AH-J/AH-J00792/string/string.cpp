#include<bits/stdc++.h>
using namespace std;
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len=1,ans=0;
	cin >> n;
	for(long long i=1;i<=n;i++){
		long long m;
		char x;
		cin >> m >> x;
		for(long long j=len;j<=len+m-1;j++){
			s[j]=x;
		}
		len+=m;
	}
	len--;
	for(long long i=1;i<=(len+1)/2;i++){
		if(s[i]!=s[len-i+1])ans++;
	}
	cout << ans;
	return 0;
}
