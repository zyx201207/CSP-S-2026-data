#include<bits/stdc++.h>
using namespace std;
long long int a[200005]={0},z[26],n=0,m=0,b;
char al[200005],bl;
void fast_io()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>al[i];
		m+=a[i];
		
	}
	int cut=0,x;
	m/=2;
	for(int i=1;i<=n;++i)
	{
		cut+=a[i];
		if(cut>=m)
		{
			x=i;
		}
	}
	cout<<m;
	return 0;
}
