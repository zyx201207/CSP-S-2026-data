#include<bits/stdc++.h>
using namespace std;
long long a,b,n[200001];
void fast_io()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
}
void g()
{
	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	int c;
	for(int i=1;i<=a;++i)
	{
		cin>>n[i];
		c=max(n[i],n[i-1]);
	}
	cout<<c;
	return 0;
}
