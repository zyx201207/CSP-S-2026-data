#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],i,j,ans;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(i=1;i<=n;i++)scanf("%lld %c",&a[i],&b[i]);
	for(i=1,j=n;i<j;){
		if(a[i]>=a[j]){
			if(b[i]==b[j])a[i]-=a[j],j--;
			else a[i]-=a[j],ans+=a[j],j--;
		}else{
			if(b[i]==b[j])a[j]-=a[i],i++;
			else a[j]-=a[i],ans+=a[i],i++;
		}
	}
	printf("%lld",ans);
	return 0;
}
