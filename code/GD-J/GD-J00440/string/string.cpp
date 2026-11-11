#include<bits/stdc++.h>
using namespace std;
long long n,len,b[200010],ans;
char a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>b[i]>>a[i];
		len+=b[i];
	}
	if (len%2==1)
	{
		long long l=1,r=len,i=1,j=n;
		while (l<=len/2 && r>=len/2+2)
		{
			if (a[i]!=a[j])
			{
				ans+=min(b[i],b[j]);
			}
			l+=min(b[i],b[j]);
			r-=min(b[i],b[j]);
			if (b[i]>b[j])
			{
				b[i]-=b[j];
				j--;	
			}else if (b[i]<b[j])
			{
				b[j]-=b[i];
				i++;
			}else
			{
				i++;
				j--;
			}
		}
	}else
	{
		long long l=1,r=len,i=1,j=n;
		while (l<=len/2 && r>=len/2+1)
		{
			if (a[i]!=a[j])
			{
				ans+=min(b[i],b[j]);
			}
			l+=min(b[i],b[j]);
			r-=min(b[i],b[j]);
			if (b[i]>b[j])
			{
				b[i]-=b[j];
				j--;	
			}else if (b[i]<b[j])
			{
				b[j]-=b[i];
				i++;
			}else
			{
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
