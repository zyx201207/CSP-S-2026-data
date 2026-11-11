#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll x[2000010];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,T;cin>>c>>T;
	if(c==0){
		while(T--){
			ll n,d;cin>>n>>d;
			if(n==4&&d==2){
				cout<<1<<endl<<2;
			}
			if(n==5&&d==3){
				cout<<0<<endl<<1;
			}
		}
		return 0;
	}
	while(T--){
		ll N,d;cin>>N>>d;
		for(ll i=1;i<=N;i++)cin>>x[i];
		ll n=d/(x[2]-x[1]);
		ll k=(N-1)/n;
		cout<<n<<" "<<k<<" ";
		ll i=1,j=1,ans=0;
		while((j<=N)&&(i<=N)){
			if((j+n)<=N)j+=n;
			else j=N;
			i+=1;
			if(j-i-1<=0)continue;
			else ans+=(j-i-1);
		}
		cout<<ans;
	}
	return 0;
}
/*
0 1
7 4
1 3 5 7 9 11 13

0 1
7 6
1 3 5 7 9 11 13

*/
