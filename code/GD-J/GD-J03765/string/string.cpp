#include<iostream>
using namespace std;
long long ans,num[200000000],n;
char a[200000000];
int main()
{
	freopen("string.in","r",stdin);	
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		cin>>a[i];
	}
	for(int i=1;i<=n/2;i++)
	{
		if(a[i]!=a[n-i+1])
		{
			if(num[i]!=num[n-i+1])
				ans+=min(max(num[i],num[n-i+1])-min(num[i],num[n-i+1]),min(num[i],num[n-i+1]));
			else 
				ans+=min(num[i],min(num[i],num[n-i+1]));
			
		}
	}
	cout<<ans;
	return 0;
} 
