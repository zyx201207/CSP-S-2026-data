#include <bits/stdc++.h>
using namespace std;
int n,len,x[200050],y[200050];
long long sum;
char a[200050],b[200050];
int d(int v,int m)
{
//	cout<<v<<' '<<m<<endl;
//	cout<<x[v]<<' '<<a[v]<<' '<<y[m]<<' '<<b[m]<<endl;
	if(v>(n+1)/2||m>(n+1)/2)
	{
		return 0;
	}
	if(a[v]!=b[m])
	{
		//wfl(max(x[v],y[m]));
		sum+=min(x[v],y[m]);
		//cout<<sum<<endl;
	}
	if(x[v]>y[m])
	{
		x[v]-=y[m];
		d(v,m+1);
	}
	else if(x[v]==y[m])
	{
		d(v+1,m+1);
	}
	else
	{
		y[m]-=x[v];
		d(v+1,m);
	}
	return 0;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>a[i];
		y[n-i+1]=x[i];
		b[n-i+1]=a[i];
	}
	d(1,1);
//	for(int i=f;i>=1;i--)
//	{
//		if(sum[i]==0)
//		{
//			f--;
//		}
//		else
//		{
//			break;
//		}
//	}
    cout<<sum;
	return 0;
}
