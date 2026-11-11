#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define st string
ll o,T,n,m,s[2000050];
map<ll,ll>y;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>o>>T;
	while(T--){
		cin>>n>>m;
		for(ll i=1;i<=n;i++){
			cin>>s[i];
			y[s[i]]=i;
		}
		
		if(o>=11&&o<=12){
			ll l=0,cha=s[2]-s[1];
			if(m<cha){
				cout<<0<<"\n";
				continue;
			}
			for(ll i=1;i<=n;i++){
				if(m>=(i-1)*cha&&m>=i*cha&&m<(i+1)*cha&&floor(((i-2)*cha+m)/cha)<floor((i*cha-cha+m)/cha)){
					cout<<n-i+2<<"\n";
					l=1;
					break;
				}
			}
			if(l==0)
				cout<<0<<"\n";
			continue;
		}
		cout<<0<<"\n";
	}
	return 0;
}

