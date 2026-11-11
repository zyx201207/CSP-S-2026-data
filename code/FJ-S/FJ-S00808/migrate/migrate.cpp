#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n; 
long long d,x[N];  
int main()
{
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    { 
		cin>>n>>d;
	    for(int i=1;i<=n;i++)
			cin>>x[i];
		long long a=x[2]-x[1],b=d/a,ans=0;
		for(int i=b+2;i<=min(b*2,1ll*n);i++)
		    ans+=(n-i+1);
		cout<<ans<<endl;
	}
    return 0;
}
