#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e9+5;
long long n,a[N],t=0,ans=0;
char c[N];
char s[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[++t]=c[i];
		}
	}
	for(long long i=1;i<=t/2;i++){
		if(s[i]==s[t-i+1]) continue;
		else ans++;
	}
	printf("%d",ans);
	return 0;
}
