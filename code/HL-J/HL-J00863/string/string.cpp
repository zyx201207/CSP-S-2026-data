#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,lon,ans;
struct node{
	ll lon=0;
	ll L=0,R=0;
	char t;
}a[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		ll i1;
		char i2;
		scanf("%lld",&i1);
		i2=getchar();
		while(i2>'z'||i2<'a'){
			i2=getchar();
		}
		lon+=i1;
		if(a[m].t==i2){
			a[m].lon+=i1;
		} else {
			m++;
			a[m].lon=i1;
			a[m].t=i2;
		}
	}
	n=m;
	for(ll i=1;i<=n;i++){
		a[i].L=a[i-1].R+1;
		a[i].R=a[i].L+a[i].lon-1;
		//cout<<" ->"<<i<<" "<<a[i].t<<" "<<a[i].lon<<" "<<a[i].L<<" "<<a[i].R<<endl;
	}
	ll L=1,R=n,l=0;
	while(L<=R){
		if(a[L].t!=a[R].t){
			ans+=min(a[L].R-l,lon-l-a[R].L+1);
			//cout<<" -"<<a[L].R-l<<" "<<lon-l-a[R].L+1<<" "<<ans<<endl;
		}
		l=min(a[L].R,lon-a[R].L+1);
		if(a[L].R<lon-a[R].L+1){
			L++;
			//cout<<" ="<<L<<" "<<R;
		} else {
			R--;
			//cout<<" >"<<L<<" "<<R;
		}
		//cout<<" "<<l<<endl;
	}
	printf("%lld",ans);
	return 0;
}
/*

*/