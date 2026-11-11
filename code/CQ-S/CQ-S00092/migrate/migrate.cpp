#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],ans;
int main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c!=0) return 0;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		
		cout<<n-d<<"\n";
	}              
	return 0;
}


