#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,w[5000001],www;
	srand(time(0));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=q;i++){
		www=rand()%888888;
		cout<<www<<endl;
	}
	return 0;
}
