#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,p;
ll a[50005];
ll b[50005];
struct dist{
	ll u,w;
}s[10005][10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&p);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=n;i++){
		ll k;
		scanf("%lld",&k);
		b[i]=k;
		for(ll j=1;j<=k;j++){
			scanf("%lld%lld",&s[i][j].u,&s[i][j].w);
		}
	}
	for(ll i=1;i<=p;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll cnt=0;
		cnt+=a[x]+a[y];
		bool temp=false;
		bool look=false;
		for(int j=x;j<=n;j++){
			if(look==true)	break;
			for(int k=1;k<=b[i];k++){
				if(s[j][k].u<=y){
					if(temp==false){
						cnt+=s[j][k].w;
						temp=true;	
					}
					else{
						cnt+=s[j][k].u;
						temp=false;
					}
					temp=!temp;
					if(s[j][k].u==y){
						look=true;
						break;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
