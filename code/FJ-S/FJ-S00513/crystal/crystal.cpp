#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=500010;
//struct node{
//	ll w;
//	ll t;
//}f[N];
ll n,m;
ll a[N];
ll w=0,t=1,d,mx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=2,r=1;i<=n;i++){
		d=a[i]-a[i-1];
		w+=t*d;
		t++;
		while(w>m){
			w-=a[i]-a[r];
			r++;
			t--;
		}
		mx=max(mx,t);
		//cout<<w<<' '<<t<<endl;
	}
	cout<<mx<<endl;
	return 0;
}
