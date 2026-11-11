#include<bits/stdc++.h>
using namespace std;
long long binary[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	int i;
	int num[n];
	int p,r;//p为商，r为余数。num[i]=2p+r。 
	int binnum;
	int max;
	if(m=1)
	{
		max=num[0];
		for(i=0;i<n;i++)
		{
			if(max<num[i])
			{
				max=num[i];
			}
		}
		cout<<max;
	}
	if(m=n)
	{
		max=num[i];
		for(i=1;i<n;i++)
		{
			max=num[i]&max;
		}
		cout<<max;
	}
}
