#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[2000005],ans[2000005];
int island()
{
	if(d==1 || n<=3) return 0;
	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int k=1;k<=n;k++) cin>>x[k];
		ans[i]=island();
	}
	for(int i=1;i<=t;i++) cout<<ans[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
