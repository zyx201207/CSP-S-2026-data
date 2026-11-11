#include<bits/stdc++.h>
#define int long long
using namespace std;
int id,T,n,d,x[2000005],len,ans;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>id>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(d<2*(x[2]-x[1])){
			cout<<0<<"\n";
		}
		len=d/(x[2]-x[1]);
		for(int i=2;i<=n;i++){
			if(i>=4&&1+2*len-1==i){
				ans+=(n-i+1);
			}
		}
		cout<<ans<<"\n";
	}
}
