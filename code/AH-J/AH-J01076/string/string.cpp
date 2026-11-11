#include<bits/stdc++.h>
using namespace std;
int main()
{

	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	
	long long n,i,j;
	cin>>n;
	long long a[1000005];
	char c[1000005];
	long long cnt=0,ans=0;
	//
	for(int i=1;i<=n;i++)
	{	
		cin>>a[i];
		cin>>c[i];
		cnt+=a[i];
	}
	int mid=cnt/2;
	i=1;
	j=n;
	while(i<=mid)
	{
		if(a[i]==a[j]&&c[i]==c[j])
		{
			i++;
			j--;
		}
		if(a[i]<a[j]&&c[i]==c[j])
		{
			i++;
			a[j]-=a[i];
		}
		if(a[i]>a[j]&&c[i]==c[j])
		{
			j--;
			a[i]-=a[j];
		}
		//
		if(a[i]==a[j]&&c[i]!=c[j])
		{
			ans+=a[i];
			i++;
			j--;
		}
		if(a[i]<a[j]&&c[i]!=c[j])
		{
			ans+=a[i];
			i++;
			a[j]-=a[i];
		}
		if(a[i]>a[j]&&c[i]!=c[j])
		{
			ans+=a[j];
			j--;
			a[i]-=a[j];
		}	
	}
	cout<<ans;
	
	return 0;
}
