#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,m[2000005],k[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>m[i];
		if(d==2)k[i]=n;
		else k[i]=0;
	}for(int i=1;i<=t;i++)cout<<k[i]<<endl;
	return 0;
}
