#include<bits/stdc++.h>
using namespace std;
long long a[100000000];
int main()
{
	//freopen("crystal1.in","r",stdin);
    //freopen("crystal1.out","w",stdout);
	int sum=1,z=0,n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
    }
    int f=n/2;
    for(int j=f-1;j>=0;j--)
	{
	    if(a[f]-a[f-1]<=m)
        {
	   	    m=m-a[f]-a[j];
	        sum++;
		}
		n--;
	}
	cout<<sum;	
}
