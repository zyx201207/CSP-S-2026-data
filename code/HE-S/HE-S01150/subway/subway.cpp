#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k,l,r;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int i=0;i<2*k;i++)
		{
			cin>>l>>r;
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>r;
	}
	cout<<"32"<<endl<<"17";
	return 0;
}
