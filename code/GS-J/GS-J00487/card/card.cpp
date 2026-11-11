#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int i;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i;i<n;i++)
	{
		for(int j;j<n;j++)
		{
			if(a[i]==a[i+1])
			{
				sum+=1;
				}	
		}
		b[i]=sum;
	 } 
	 fot(int i;i<m;i++)
	 {
	 	cout<<b[i];
	 }
}


