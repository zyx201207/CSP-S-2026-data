//GZ-J00483 六盘水市第四实验中学  王本贤
#include<bits/stdc++.h>
using namespace std;
long long n,a[20005];
char z[20005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>z[i];
	}
	long long sum=0;
	for(int i=1,j=n;i<=j,j>=i;i++,j--)
	{
		if(z[i]!=z[j]&&a[i]!=0&&a[j]!=0)
		{
			if(a[i]>a[j])
			{
				sum+=a[j];
				a[i]-=a[j];
				a[j]=0;
				i--;
			}
			else if(a[i]<a[j])
			{
				sum+=a[i];
				a[j]-=a[i];
				a[i]=0;
				j++;
			}
			else if(a[i]==a[j])
			{
				sum+=a[i];
				a[i]=0;
				a[j]=0;
			}
		}
	}
	cout<<sum;
	return 0;
}
