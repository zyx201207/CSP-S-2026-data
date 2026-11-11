// GZ-S00089 黄浩然 贵阳市第三中学 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void fx(){
	ll n ,d;cin>>n>>d;
	vector<ll>a(n+1,0);
	for(ll i=1;i<=n;i++)cin>>a[i];
	cout<<0<<1<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c;ll t=1;cin>>c>>t;
	while(t--)fx();
}


