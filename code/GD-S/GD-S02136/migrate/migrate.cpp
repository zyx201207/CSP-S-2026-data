#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=2*1e6;
long long a[MAXN],sum=0;
int sfind(int i,int m)
{
	for(int j=0;j<m;j++)
	{
		if(a[j]==i) return 1;
	}
	return 0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	int c,n,m,d;
    cin>>c>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>m>>d;
    	for(int j=0;j<m;j++)
    	{
    		cin>>a[i];
		}
		for(int l=0;l<10;l++)
		{
			for(int r=m-1;r<l;r--)
			{
				if(sfind((a[r]-d),m)&&sfind((a[l]+d),m)&&sfind((a[l]+2*d),m))
				{
					sum++;
				}
			}
		}
		cout<<sum<<endl;
		sum=0;
	}
    return 0;
}
