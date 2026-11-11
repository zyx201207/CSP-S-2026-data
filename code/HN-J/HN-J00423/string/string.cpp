#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long ans=0;//½á¹û 
	int j=n;
	for(int i=1;i<=n&&j>=1&&i<=j;)
	{
		while(a[i]>a[j])
		{
			if(c[i]!=c[j])
			{
				ans+=a[j];
			//	cout<<i<<" "<<j<<" "<<a[i]<<endl;
			}
			a[i]-=a[j];
			sum-=a[j]*2;
			j--;
		}
		while(a[j]>a[i])
		{
			if(c[i]!=c[j])
			{
				ans+=a[i];
			//	cout<<i<<" "<<j<<" "<<a[j]<<endl;
			}
			a[j]-=a[i];
			sum-=a[i]*2;
			i++;
		}
		if(a[i]==a[j])
		{
			sum-=a[i]+a[j];
			if(c[i]!=c[j])
			{
				ans+=a[i];
			//    cout<<i<<" "<<j<<" "<<a[i]<<endl;
			}
			a[j]=0;
			a[i]=0;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
