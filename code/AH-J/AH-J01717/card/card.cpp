#include<bits/stdc++.h>
using namespace std;
string a,dach,t;
long long n,m,f[5000005];
char x[5000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		a=a+x[i];
		f[x[i]-'0']++;
	}
	for(int i=1;i<=n;i++)
	{
		t=a;
		for(int j=0+(i-1);j<n;j++)
		{
			if(dach.find(t[j])!=18446744073709551615)
			{
				dach.erase(dach.find(t[j]),t.size());
				dach=dach+t[j];
			}
			else
			{
				dach=dach+t[j];
			}
		}
		for(int j=0;j<dach.size();j++)
		{
			
		}
	}
}
