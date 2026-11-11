#include<bits/stdc++.h>
using namespace std;
long long a,b,as[500001],bs[500001],out,l,r,m;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>as[i];
	}
	sort(as+1,as+a+1);
	for(int i=1;i<=a;i++)
	{
		bs[i]=bs[i-1]+as[i];
		for(l=1,r=i;l<r;)
		{
			m=(l+r)/2;
			if(as[i]*(i-m+1)-bs[i]+bs[m-1]>b)l=m+1;
			else r=m;
		}
		out=max(out,i-r+1);
	}
	cout<<out;
	return 0;
}
