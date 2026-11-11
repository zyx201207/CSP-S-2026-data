#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],b[N],n;
char c[3];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%s",&a[i],c+1),b[i]=c[1]-'a';
	long long ans=0;bool pd=0;
	for(int i=1,j=n;i<j;)
	{
//		printf("%lld %lld\n",i,j);
		int x=min(a[i],a[j]);
		ans+=1ll*(b[i]!=b[j])*x;
		a[i]-=x;a[j]-=x;
		if(!a[i])i++;
		if(!a[j])j--;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
