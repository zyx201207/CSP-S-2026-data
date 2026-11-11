#include<bits/stdc++.h>
using namespace std;
const int N=200100;
long long a[N],cnt,n,k;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %c",&a[i],&c[i]);
	}
	for(int i=1,j=n;i<j;)
	{
		if(c[i]==c[j])
		{
			if(a[i]==a[j]) i++,j--;
			else if(a[i]>a[j]) a[i]-=a[j],j--;
			else if(a[i]<a[j]) a[j]-=a[i],i++;
		}
		else
		{
			if(a[i]==a[j]) cnt+=a[i],i++,j--;
			else if(a[i]>a[j]) a[i]-=a[j],cnt+=a[j],j--;
			else if(a[i]<a[j]) a[j]-=a[i],cnt+=a[i],i++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
