#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a[200005];
	char b[200005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	if(n==2)
	{
		if(b[1]==b[2])
		{
			cout<<"0";
			return 0;
		}
		else
		{
		cout<<"1";
		return 0;
		}
		
	}
	int m=1;
	long long sum=0;
	for(int i=1;i<=n/2;i++)
		{
			if(a[m]!=a[i]&&b[m]!=b[i])
			{
				if(a[m]>a[i])
				{
					sum+=a[m];
				}
			}
		}
		cout<<sum;
	return 0;
} 
