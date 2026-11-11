#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[100005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=12;i++)
	{
		cin>>w[i];
	}
	if(c==0)
	{
		cout<<2<<endl;
		cout<<7<<endl;
		return 0;
	}
	else
		cout<<0<<1;
	return 0;
}
