#include<bits/stdc++.h>
using namespace std;
long long a[2000100];
char c[2000100],b[2000100];
string str;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,j,k;
	long long ans=0,mid1,mid2,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(j=1;j<=a[i];++j)
		{
			b[j]=c[i];
		}
	}
	if(sum%2==1)
	{
		mid1=ceil(1.00*sum/2);
		for(i=0;i<=mid1-2;++i)
		for(k=sum-1;k>=mid1;k--)
		{
			if(b[i]!=b[k]) ans++;
			break;
		}
	}
	else
	{
		mid1=sum/2;
		mid2=sum/2+1;
		for(i=0;i<=mid1-1;++i)
		{
			for(k=sum-1;k>=mid2+1;k--)
			{
				if(b[i]!=b[k]) ans++;
				break;
			}
		}
		if (b[mid1]!=b[mid2]) ans++;
	}
	 cout<<ans;
	 return 0;
}

