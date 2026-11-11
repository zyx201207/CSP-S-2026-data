#include <iostream>
using namespace std;
long long a[11111111],b[11111111],c[11111111],f[11111111];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>> n >>m;
	int t = 1;
	for(int i = 1;i <= n;i++)
	{
		cin>> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		t = 1;
		for(int j = 1;j <= n;j++)
		{
			b[i] = 0;
		}
		for(int j = i;j <= n;j++)
		{
			if(b[a[j]]==1)
			{
				t = 1;
				f[t] = a[j];
				t++;
			}
			f[t] = a[j];
			t++;
			b[a[j]]=1;
		}
		for(int j = 1;j <= t-1;j++)
		{
			c[f[j]]++;
		}
		
	}
	for(int i = 1;i <= m;i++)
	{
		cout<<c[i]<<" ";
	}
 } 
