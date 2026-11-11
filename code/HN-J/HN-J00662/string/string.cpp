#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,c=0,t=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(n>t)
	{
		if(b[t]!=b[n])
		{
			c+=min(a[t],a[n]);
			if(a[t]>a[n])
			{
				cout<<a[t]<<" "<<a[n]<<endl;
				a[t]-=a[n];
				n--;
			}
			else if(a[t]<a[n]) 
			{
				a[n]-=a[t];
				t++;
			}
			else
			{
				n--;
				t++;
			}
		}
		else
		{
			if(a[n]>a[t])
			{
				a[n]-=a[t];
				t++;
			}
			else if(a[n]<a[t])
			{
				a[t]-=a[n];
				n--;
			}
			else
			{
				n--;
				t++;
			}
		}
	}
	cout<<c;
	return 0;
}
