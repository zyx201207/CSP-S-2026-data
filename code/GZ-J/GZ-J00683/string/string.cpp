//GZ-J00683 遵义市第十二中学 兰至立 
#include<bits/stdc++.h>
using namespace std;
long long a[1000005],m,n=0,sum=0;
char b[1000005];
string c="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
		;
		n+=a[i];
	}
	int j=m;
	for(long long i=1;i<=j;i++)
	{
		if(b[i]!=b[j])
		{
			if(a[i]>a[j])
			{
				sum+=a[j];
				a[i]-=a[j];
				if(a[i])
				{
					i--;
				}
			}
			else
			{
				sum+=a[i];
				a[j]-=a[i];
				if(a[j])
				{
					j++;
				}
			}
			j--;
		}
	}
	cout<<sum;
	return 0;
}
