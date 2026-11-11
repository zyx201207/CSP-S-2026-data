#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,ans=0;
	cin>>c>>t;
	while(t--){
		ans=0;
		int n,d,x[2000005];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=d+2;i<=n;i++){
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
