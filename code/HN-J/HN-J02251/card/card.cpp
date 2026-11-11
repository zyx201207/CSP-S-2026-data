#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000005];
long long t[300005]; 
long long w[1000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		
		int tt=0;
		for(int j=i;j<=n;j++)
		{
			tt++;
			for(int k=1;k<=tt;k++)
			{
				if(w[tt]==a[k])
				{
					tt=k;
					cout<<"xx";
				}
				
			}
			w[tt]=a[j];
			
		
		}
		for(int j=1;j<=tt;j++)
		{
			t[w[j]]++;
			cout<<i<<"  "<<w[j]<<endl;
		}
		
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}
// Trick||Treat! 
