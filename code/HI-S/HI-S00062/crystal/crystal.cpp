#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx,len=1,ml;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(long long i=1;i<n;i++){
		ml+=(a[i]-a[i-1])*len;
		len++;
		while(ml>m){
			len--;
			ml-=(a[i]-a[i-len]);
		}
		maxx=max(maxx,len);
	}
	printf("%lld",maxx);
	return 0;
}
