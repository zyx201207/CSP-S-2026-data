//GZ-J00104 贵州省瓮安第二中学 严云涵 
#include <bits/stdc++.h>
using namespace std;
string a[20005];
long long b[20005];
int num;
int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> b[i];
		cin >> a[i];
	}
	for (int i=1;i<=n/2;i++)
	{
		int sum=0;
		if(a[i]==a[n-i+1])
		{
			if(b[i]>b[n-i+1])
			{
				sum=b[i]-b[n-i+1];
				b[i]=b[n-i+1];
				b[i+1]+=sum;
				if(a[i+1]!=a[i])
				{
					num+=sum;
				}
			}
			else if(b[i]<b[n-i+1])
			{
				sum=b[n-i+1]-b[i];
				b[n-i+1]=b[i];
				b[n-i]+=sum;
				if(a[n-i]!=a[n-i+1])
				{
					num+=sum;
				}
			}
		}
		else
		{
				if(b[i]>b[n-i+1])
			{
				num+=b[n-i+1];
				sum=b[i]-b[n-i+1];
				b[i]=b[n-i+1];
				b[i+1]+=sum;
				
				if(a[i+1]!=a[i])
				{
					num+=sum;
				}
			}
			else if(b[i]<b[n-i+1])
			{
				num+=b[i];
				sum=b[n-i+1]-b[i];
				b[n-i+1]=b[i];
				b[n-i]+=sum;
				if(a[n-i]!=a[n-i+1])
				{
					num+=sum;
				}
			}
		}
			
	}
	cout << num;
	return 0;
}
