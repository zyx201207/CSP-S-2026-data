/*LA FLAMME SURVIT SOUS LA PLUIE DEPUIS TANT D'HIVERS
LE SANG VERSÉ LIE NOS ÂMERE FIÈRES
LA CROIX DE LORRAINE NOUS ÉCLAIRE
VER PARIS ET VER LA MER*/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[507891],s[507891];
void rp(int rp){
	while(1)rp++;
}
bool check(int x){
	for(int i=x;i<=n;i++){
		if(a[i]*x-s[i]+s[i-x]<=m)return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(l==mid)break;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
}

