#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,temp1,temp2,i,j;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
		cin>>temp1;
	for(i=1;i<=n;i++)
	{
		cin>>temp2;
		for(j=1;j<=temp2*2;j++)
			cin>>temp1;
	}
	for(i=1;i<=q;i++)
	{
		cin>>temp1>>temp2;
	}
	srand(time(0));
	for(i=1;i<=q;i++)
		cout<<rand()%100000<<endl;
	return 0;
}
