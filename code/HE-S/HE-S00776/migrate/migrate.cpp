#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long t,s,n,d,p,sum=0,l;
	bool o=true;
	cin>>t>>s;
	for(int i=1;i<=s;i++)
	{
		cin>>n>>d;
		long long m[n+5];
		for(int j=1;j<=n;j++)
		{
			cin>>m[j];
		}
		for(int j=1;j<=n-3;j+=2)
		{
			if(m[j+1]-m[j]<d&&m[j+2]-m[j]<=d)
			{
				if(m[j+3]-m[j]>d)
				{
					sum++;
				}
			}
		}
		cout<<sum<<endl; 
	}
	return 0;
}
