#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,n,m,d,q;
	int w[500005],k[505],r[100005];
	long long t[1000000005];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>r[i];
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=q;j++)
		{
			t[i]=w[r[1]]+t[i]+w[r[q]];
		}
		cout<<t[i]<<endl;
	}
	
	return 0;
}
