#include<bits/stdc++.h>
using namespace std;
#define ll long long


const int N=2e5+5;
struct shu{
	ll b;
	char s;
}a[N];


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].b>>a[i].s;
	}
	int l=1,r=n;
	ll lz=a[l].b,rz=a[r].b;
	ll ans=0;
	while(l<r){
		if(a[l].s!=a[r].s){
			ans+=min(lz,rz);
		}
		if(lz<rz){
			rz=rz-lz;
			lz=a[l+1].b;
		}
		else if(lz>rz){
			lz=lz-rz;
			rz=a[r-1].b;
		}
		else{
			lz=a[l+1].b;
			rz=a[r-1].b;
		}
		if(lz==a[l+1].b){
			l++;
		}
		if(rz==a[r-1].b){
			r--;
		}
	}
	cout<<ans;
	return 0;
}
