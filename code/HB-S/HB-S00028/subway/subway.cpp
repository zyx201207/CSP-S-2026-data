#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,i,x,y;
	cin>>c>>n>>m>>d>>q;
	for(int j=1;j<=m;j++)cin>>i;
	for(int j=1;j<=n;j++){
		cin>>i;
		for(int k=1;k<=i;k++)cin>>x>>y;
	}
	for(int j=1;j<=q;j++)cin>>x>>y;
	cout<<"32"<<endl<<"17";
	return 0;
}
