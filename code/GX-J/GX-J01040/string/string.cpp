#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[210002],i,j,k=0;
	char c[210002];
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>c[i];
	j=n;
	i=1;
	while(i<j)
	{
		if(c[i]==c[j]&&a[i]==a[j])
		{
			k=k+0;
		}else{
			if(c[i]==c[j]&&a[i]>a[j])
			{
				a[i]=a[i]-a[j];
				j--;
			}else{
				if(c[i]==c[j]&&a[i]<a[j])
				{
					a[j]=a[j]-a[i];
					i++;
				}else{
					if(a[i]==a[j])
		{
			k=k+a[j];
			j--;
			i++;
		}else{
			if(a[i]<a[j])
			{
				k=k+a[i];
				a[j]=a[j]-a[i];
				i++;
			}else
			{
							if(a[i]>a[j])
							{
								k=k+a[j];
								a[i]=a[i]-a[j];
								j--;
							}
						}
					}
				}
			}
		}
	}
	cout<<k;
	return 0;
}
