#include<bits/stdc++.h>
using namespace std;
long long n,a,ans,sum=1;
char c,s[1000000005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) {
		cin>>a>>c;
		for(long long j=0;j<a;j++) {
			s[sum+j]=c;
		}
		sum+=a;
	}
	for(long long i=1;i<=sum/2;i++) {
		if(s[i]!=s[sum-i]) ans++;
	}
	cout<<ans;
	return 0;
}