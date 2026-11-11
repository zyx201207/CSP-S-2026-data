#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,d,x[2000007];

void sol(){
	cin>>n>>d;
	ll ans=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(n<=2){
		cout<<0<<"\n";
		return ;
	}
	ll jj=x[2]-x[1];
	if(jj>=d){
		cout<<0<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		if(i+3<=n&&x[i+3]-x[i]>=d&&x[i+2]-x[i]<=d)++ans;
		if(i-3>=1&&x[i]-x[i-3]>=d&&x[i]-x[i-2]<=d)++ans;
	}
	cout<<ans/2<<"\n";
}

ll c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sol();
	}
	
	
}

