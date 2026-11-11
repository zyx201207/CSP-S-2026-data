#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long x[n];
	for(long long i=0;i<n;i++)
	cin>>x[i];
	sort(x,x+n);
	if(m==1)
	{
		cout<<x[n-1];
		return 0;
	}
	long long w=0;
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<n;j++)
		{
			if((x[i]&x[j]>w)&&(i!=j))
				w=x[i]&x[j];
		}
	}
	cout<<w;
	return 0;
}