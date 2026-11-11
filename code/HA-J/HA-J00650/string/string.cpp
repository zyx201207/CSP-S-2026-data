#include <bits/stdc++.h>
using namespace std;
int a[1000010],n;
int b[1000010];
char c[1000010],op[3];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
		scanf("%s",op+1);
		c[i]=op[1];
	}
	int i=1,j=n;
	long long ans=0;
	while(i<=n&&j>=1)
	{
		if(a[i]==b[j])
		{
			if(c[i]!=c[j]) ans+=a[i];
			i++;j--;
		}
		else if(a[i]>b[j])
		{
			if(c[i]!=c[j]) ans+=b[j];
			a[i]-=b[j];j--; 
		}
		else if(a[i]<b[j])
		{
			if(c[i]!=c[j]) ans+=a[i];
			b[j]-=a[i];i++;
		}
	}
	cout<<ans/2<<endl;
	return 0;
}
