#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
char s[N];
long long pos=1;
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&s[i]);
//		printf("%d%c",a[i],s[i]);
		pos+=a[i];
	}
	int i=1,j=n;
	long long L=1,R=pos;
	while(i<j)
	{
		int mn=min(a[i],a[j]);
		if(s[i]!=s[j])
			ans+=mn;
//		cout<<i<<" "<<j<<"\n";
		if(a[i]<a[j])
			a[j]-=a[i++];
		else if(a[j]<a[i])
			a[i]-=a[j--];
		else
			i++,j--;
	}
	printf("%lld\n",ans);
	return 0;
}

