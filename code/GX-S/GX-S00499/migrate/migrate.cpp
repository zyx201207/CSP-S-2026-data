#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
int n;
ll d,x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ll ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(x[n]-x[1]<=d){cout<<0<<endl;continue;}
		int i=2;
		while(x[i]-x[1]<=d)i++;
		ans=n-i+1;
		cout<<ans<<endl;
	}
	return 0;
}
		
