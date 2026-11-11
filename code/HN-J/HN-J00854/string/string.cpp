#include<bits/stdc++.h>
using namespace std;
int a;
string m[200005];
long long hod,n[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>n[i]>>m[i];
	}
	for(int j=0,i=a;i!=j;)
	{
		if(m[j]!=m[i])
		{
			if(n[j]>n[i])
			{
				hod+=n[i];
				n[j]-=n[i];
				i--;
			}
			else
			{
				hod+=n[j];
				n[i]-=n[j];
				j++;
			}
		}
		else
		{
			if(n[j]>n[i])
			{
				n[j]-=n[i];
				i--;
			}
			else
			{
				n[i]-=n[j];
				j++;
			}
		}
	}
	cout<<hod;
	
	return 0;
} 
