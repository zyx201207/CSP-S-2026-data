#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue
#define st stack
#define qu queue
#define qwq ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define N 500005
#define M 300005
ll n=0,m=0;
ll a[N]={0};
ll b[M]={0};
ll c[M]={0};
ll d[N]={0};
void solve(ll e){
	for(ll i=1;i<=m;i++){
		b[i]=0;
	}
	ll f=1;
	for(ll i=e;i<=n;i++){
		if(b[a[i]]==1){
			ll g=0;
			for(ll j=1;j<=f;j++){
				if(d[j]==a[i]){
					g=j;
				}
			}
			for(ll j=g;j<=f-1;j++){
				b[d[j]]=0;
			}
			d[1]=a[i];
			f=2;
			b[a[i]]=1;
		}else{
			b[a[i]]=1;
			d[f]=a[i];
			f++;
		}
	}
	for(ll i=1;i<=m;i++){
		c[i]+=b[i];
	}
}
int main(){
	qwq;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		solve(i);
	}
	for(ll i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
//		ll flag=1,e=0;
//		for(ll j=1;j<d;j++){
//			if(b[j]==a[i]){
//				flag=0;
//				e=j;
//			}
//		}
//		if(flag){
//			b[d]=a[i];
//		}else{
//			d=e+1;
//		}
