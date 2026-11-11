#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[10010];
ll w[10010];
ll t[10010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q,ljh=0,ljs=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>k[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==a[j+m]){
				ljh==a[i]+a[j+m];
			}
			for(int i=1;i<=d;i++){
		for(int j=1;j<=q;j++){
			if(a[i]==a[j+m]){
				ljs==a[i]+a[j+m];
			}
			cout<<ljh<<endl<<ljs;
			
return 0;
}
		
			
