#include<iostream>
#include<cmath>
using namespace std;
string a,b,c[200000];
long long n,k[200000];
long long f,u,o,uds=1,ods,sum,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i]>>c[i];
		f+=k[i];
	}
	ods=n;
	while(u<f-o)
	{
		if(u+k[uds]>o+k[ods])
		{
			if(c[ods]==c[uds])
			{
				o+=k[ods];
				ods--;
				continue;
			}
			else
			{
				sum+=min(o+k[ods]-u,k[ods]);
				o+=k[ods];
				ods--;
			}
		}
		if(u+k[uds]<o+k[ods])
		{
			if(c[ods]==c[uds])
			{
				u+=k[uds];
				uds++;
				continue;
			}
			else
			{
				sum+=min(u+k[uds]-o,k[uds]);
				u+=k[uds];
				uds++;
			}
		}
		if(u+k[uds]==o+k[ods])
		{
			if(c[ods]==c[uds])
			{
				cout<<u+k[uds];
				cout<<o+k[ods];
				o+=k[ods];
				u+=k[uds];
				uds++;
				ods--;
				continue;
			}
			else
			{
				cout<<u+k[uds];
				cout<<o+k[ods];
				sum+=min(u+k[uds]-o,k[uds]);
				u+=k[uds];
				o+=k[ods];
				uds++;
				ods--;
			}
		}
	}
	cout<<sum;
}
