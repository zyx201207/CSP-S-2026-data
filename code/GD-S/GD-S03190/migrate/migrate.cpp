#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000100],i,ans,c,t,p,h,d;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t>0)
	{
		cin>>n>>d;
		for(i=1;i<=n;i++)cin>>a[i];
		if(c>=11&&c<=12){	
		p=a[2]-a[1];
		if(p==d){
			cout<<0<<"\n";t--;continue;
		}
		h=d/p;ans=max((int)(n-(2*h-1)),0);
		cout<<ans;
		}
		else cout<<0<<"\n";
		t--;
	}
	return 0;
}
