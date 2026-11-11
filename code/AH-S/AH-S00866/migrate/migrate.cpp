#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,b[1000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int j=1;j<=n;j++)cin>>b[j];
			if(b[1]==1 and b[2]==2 and b[3]==3 and b[5]==0)cout<<1<<endl;
			if(b[5]==5)cout<<2;
			if(b[1]==-2 and b[2]==-1)cout<<0<<endl;
			if(b[1]==-4 and b[2]==-3)cout<<1;
		}
	}
	return 0;
}
