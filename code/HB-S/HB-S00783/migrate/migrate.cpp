#include<bits/stdc++.h>
using namespace std;
long long c,t;
int solve(int ai,int lf,int cnt)
{
	if(ai<=lf)ans++;
	solve(ai-lf,lf,cnt++);
} 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int a,b;
		cin>>a>>b;
		int ans=0;
		solve(a,b);
		cout<<ans;
	}
	return 0;
}
