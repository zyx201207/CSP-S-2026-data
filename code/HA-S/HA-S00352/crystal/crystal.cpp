#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y)
{
	return x>y; 
}
int main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.in","w",stdout); 
	long long n,m,a[500005],cha[500005],sum[500005],k=0;
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp); 
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			cha[j]=a[i]-a[j]; 
		}
		int z=i+1;
		while (m>0)
		{
			if(m>=cha[z])
			{
				m=m-cha[z];
				sum[k]++;
				z++;
			}
			else 
			{
				break;
			}
		}
		for(int u=i+1; u<n; u++)
		{
			cha[u]=0;
		}
		if(sum[k]!=0)
		{
			k++;
		 } 
	}
	sort(sum,sum+n-1,cmp);
	cout<<sum[0]+1;
	return 0;
} 
