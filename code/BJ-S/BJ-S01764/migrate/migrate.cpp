#include<bits/stdc++.h>
using namespace std;

int n,c,t;
long long k,a[200005],d[200005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long ans=0;
		for(int i=4;i<=n;i++){
			if((a[i]-a[1])%k<=a[i]-a[i-1]&&(a[i]-a[1])%k!=0){
				ans+=n-i+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
   
