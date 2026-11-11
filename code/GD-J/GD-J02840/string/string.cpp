#include<stdio.h>
int n,a[200005];
long long cnt;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d %c",a+i,s+i);
	for(int l=0,r=n-1;l<r;)
		if(a[l]<a[r])a[r]-=a[l],cnt+=s[l]!=s[r]?a[l]:0,l++;
		else         a[l]-=a[r],cnt+=s[l]!=s[r]?a[r]:0,r--;
	printf("%lld",cnt);
	return 0;
}

