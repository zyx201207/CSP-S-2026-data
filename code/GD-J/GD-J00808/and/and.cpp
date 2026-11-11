#include<bits/stdc++.h>
using namespace std;
long long a[100001];
void bs(int a[100001],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j]<a[j+1])
			{
				int tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	bs(a,n);
	cout<<a[m];
	return 0;
}  
