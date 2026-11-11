#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll ans=0;
pair<ll,ll> a[200001];
pair<ll,ll> b[200001];
ll nowa=1;
ll nowb=1;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		ll x,y;
		char yy;
		scanf("%lld %c",&x,&yy);
		y=yy-96;
		a[i].first=x;
		a[i].second=y;
		b[n-i+1].first=x;
		b[n-i+1].second=y;
	}
	while(1){
		if(a[nowa].second==b[nowb].second){
			if(a[nowa].first>b[nowb].first){
				a[nowa].first-=b[nowb++].first;
			}else if(a[nowa].first<b[nowb].first){
				b[nowb].first-=a[nowa++].first;
			}else{
				nowa++;
				nowb++;
			}
		}else{
			if(a[nowa].first>b[nowb].first){
				ans+=b[nowb].first;
				a[nowa].first-=b[nowb++].first;
			}else if(a[nowa].first<b[nowb].first){
				ans+=a[nowa].first;
				b[nowb].first-=a[nowa++].first;
			}else{
				ans+=a[nowa].first;
				nowa++;
				nowb++;
			}
		}
		if(nowa==nowb && nowa==n+1)
			break;
	}
	printf("%lld",ans/2);
	return 0;
}
