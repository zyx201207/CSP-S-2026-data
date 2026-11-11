#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200005],l=1,r,sl,sr,ans;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	r=n;
	for(int i=1;i<=n;i++)
		scanf("%lld %c\n",&a[i],&c[i]);
	while(l<r)
	{
		if(a[l]-sl>a[r]-sr){
			if(c[l]!=c[r])ans+=(a[r]-sr);
			sl+=(a[r]-sr),sr=0,r--;
		}
		else if(a[l]-sl<a[r]-sr){
			if(c[l]!=c[r])ans+=(a[l]-sl);
			sr+=(a[l]-sl),sl=0,l++;
		}
		else if(a[l]-sl==a[r]-sr){
			if(c[l]!=c[r])ans+=(a[l]-sl);
			sl=0,l++,sr=0,r--;
		}
	}
	printf("%lld",ans);
	return 0;
}
