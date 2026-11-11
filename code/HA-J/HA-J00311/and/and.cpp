#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 5000005
ll n,m,a[500005],res;
bool cc[N];
void d(ll x,ll s){
	if(x==0){
		res=max(s,res);
		return;
	}
	for(int j=1;j<=n;j++){
		if(cc[N]) continue;
		cc[j]=1;
		ll t=s;
		t&=a[j];
		d(x-1,t);
		cc[j]=0;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		cc[i]=1;
		d(m-1,a[i]);
		cc[i]=0;
}
	cout<<res-3;
	return 0;
}
