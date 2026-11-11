#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[20000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			int l=i+1,r=n+1;
			while(l<r){
				long long m=(l+r)/2;
				if(a[m]-a[l]>=d&&m-l>=2) l=m+1;
				else r=m;
			}
			ans+=(n-l+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
