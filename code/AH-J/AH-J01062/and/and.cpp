#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[200005],sum[200005];
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	}
	if(m==2)
	{
		for(int k=0,i=0,j=1;k<((1+n-1)*n)/2;k++)
		{
			sum[k]=a[i]&a[j];
			j++;
			  if(j==n-1)
			{
				i++;
				j=i+1;	
			}
		}
		sort(sum,sum+((1+n-1)*n)/2);
		cout<<sum[(((1+n-1)*n)/2)-1];
	}
	if(m==3)
	{
		for(int k=0,i=0,j=1,f=2;;k++)
		{
			sum[k]=a[i]&a[j]&a[f];
			f++;
			  if(f==n-1)
			{
				j++;
				f=j+1;	
			}
			  if(j==n-1)
			{
				i++;
				j=i+1;	
			}
			if(i==n-1);
			break;
		}
		sort(sum,sum+k);
			cout<<sum[k];
	}
	return 0;
}
