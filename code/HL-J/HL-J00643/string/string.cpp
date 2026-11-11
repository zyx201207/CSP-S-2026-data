#include<bits/stdc++.h>
using namespace std;
int n,b,q=0,mid,sum;
char c[20001],a1[10001],a2[10001],p; 
int main()
{	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
    cin>>b;
	q+=b;
	cin>>p;
	for(int j=q-b;j<q;j++)
	{
		c[j]=p; 
	}
	}
    if(q%2!=0)
    {
    mid=(q+1)/2;
    for(int i=0;i<mid-1;i++)
    	a1[i]=c[i];
	for(int i=q;i>=mid+1;i--)
	{
		int j=0;
		a2[j]=c[i];
		j++;
	}
	}
    else
    {
    mid=q/2;
    for(int i=0;i<mid;i++)
    	a1[i]=c[i];
	for(int i=q;i>=mid;i--)
	{
		int j=0;
		a2[j]=c[i];
		j++;
	}
	}
	sum=mid;
	for(int i=0;i<=mid;i++)
	{
		if(a1[i]==a2[i])
		sum--;
	}
	cout<<sum<<endl;
    return 0;
}
