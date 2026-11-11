#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200020],as=0;
void q(int d,long long s,int l)
{
	if(n-d+1<l-m)
		return;
	if(l==m)
	{
		as=max(as,s);
		return;
	}
	q(d+1,s,l);
	if(s==0)
	{
		q(d+1,a[d],l+1);
	}
	else
	{
		q(d+1,s&a[d],l+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	q(1,0,0);
	cout<<as;
	return 0;
} 
