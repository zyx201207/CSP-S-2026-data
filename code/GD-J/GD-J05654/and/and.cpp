#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,max_num=-10,g=-1000;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>g) g=a[i];
	}
	if(m==1)
	{
		cout<<g;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		long long s=a[i];
		for(int j=i+1;j<n;j++)
		{
			s=s&a[j];
		}
		if(s>max_num) max_num=s;
	}
	cout<<max_num;
}
