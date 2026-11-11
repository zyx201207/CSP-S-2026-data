#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
ll n,m,v[N],a[N],mx,p[21]; 
void L(ll y,ll k){
	if(k==m){
		mx=max(mx,y);
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(!v[i]){
			ll ny=y&a[i];
			v[i]=1;
			L(ny,k+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(m==1){
		sort(a+1,a+n+1);
		printf("%lld",a[n]);
		return 0;
	}
	if(m==2){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(j!=i) mx=max(mx,a[i]&a[j]);
			}
		}
		printf("%lld",mx);
		return 0;
	}
	if(m==n){
		ll p=a[1];
		for(ll i=2;i<=n;i++) p&=a[i];
		printf("%lld",p);
		return 0;
	}
	for(int i=0;i<=20;i++){
		p[i]=(1<<i)-1;
	}
	int t=0;
	for(ll i=1;i<=n;i++){
		int tp=0;
		for(ll j=0;j<=20;j++){
			if(a[i]==p[j]){
				tp=1;
				break;
			}
		}
		if(!tp){
			t=1;
			break;
		}
	}
	if(!t){
		sort(a+1,a+n+1);
		printf("%lld",a[n-m+1]);
		return 0;
	}
	L(1,1);
	printf("%lld",mx);
	return 0;
} 
