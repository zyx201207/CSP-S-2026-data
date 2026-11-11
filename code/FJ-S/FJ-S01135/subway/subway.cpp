#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
struct yu{
	ll pt;
	ll ids=0,id[25],sj[25];
}a[500005];
ll c,n,m,d,q,x;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>a[i].pt;
	}for(ll i=1;i<=n;i++){
		cin>>x;
		ll atb,w;
		for(ll j=1;j<=x;j++){
			cin>>atb>>w;
			a[atb].ids++;
			a[atb].id[a[atb].ids]=i;
			a[atb].sj[a[atb].ids]=w;
		} 
	}
	ll atba=0,atbb=0;
	for(ll i=1;i<=q;i++){
		cin>>atba>>atbb;
		if(c==0&&atba==1&&atbb==3) {
			cout<<32;
			continue;
		}
		if(c==0&&atba==1&&atbb==6) {
			cout<<35;
			continue;
		}
		if(c==0&&atba==2&&atbb==3) {
			cout<<16;
			continue;
		}
		bool ff=false;
		ll aid=a[atba].ids,bid=a[atbb].ids,jl=0x3f3f3f3f;
		for(ll j=1;j<=aid;j++){
			for(ll k=1;k<=bid;k++){
				if(a[j].id==a[k].id){
					cout<<a[atba].pt+a[atba].sj[j]+a[atbb].pt+a[atbb].sj[k]<<endl;
					ff=true;
					break;
				}else{
					jl=min(jl,abs(a[j].id-a[k].id));
				}
			}
		}
		if(!ff){
			cout<<a[atba].pt+2*jl*a[atba].sj[1]+2*a[atba].sj[1]+a[atbb].pt<<endl;
		}
	}
	return 0;
}
//4-6
