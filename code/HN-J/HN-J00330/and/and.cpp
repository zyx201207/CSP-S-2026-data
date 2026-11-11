#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int mn=4e6+6;
ll n,m,p,x;
ll a[mn];
//inline int huo(ll q,ll w){
//	while(w){
//		if(w%2&&(!(q%2))) return 0;
//		w>>1;q>>1;
//	}
//	return 1;
//}
inline void fdf(ll u,ll d,ll s){
	if(d==1){
		x=max(x,u);
		return;
	}
	for(int i=1;i<=n;i++){
//		cout<<a[i]<<endl;
		if(i>=s) continue;
		if(u&a[i]) fdf(u&a[i],d-1,i);
	}
	return;
}
int main ( ) {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	
	while(1){
		if(!n) break;
		if((p|a[n])==p){
			n--;
			continue;
		}
		ll bc=a[n];
//		cout<<bc<<' ';
		n--;
		p|=bc;
		fdf(bc,m,n+1);
	}
	cout<<x;
	return 0;
} 
