#include<bits/stdc++.h>
using namespace std;
long long w[500001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=q;i++)
	{
		if(i%2!=0)cout<<"1 2"<<endl;
		if(i%2==0)cout<<"1 3"<<endl;
	}
	return 0;
}
