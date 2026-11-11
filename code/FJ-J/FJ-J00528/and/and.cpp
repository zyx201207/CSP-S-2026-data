#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],m,bt[35],ans,mx;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		for(int j=0;j<=30;j++){
			if((a[i]&(1ll<<j)))bt[j]++;
		}
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	for(int i=0;i<=30;i++){
		if(bt[i]>=m)continue;
		for(int j=1;j<=n;j++){
			if((a[j]&(1ll<<i)))a[j]-=(1ll<<j);
		}
	}
	
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=101;i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=2;i<=m;i++){
		a[i]=(a[i]&a[i-1]);
	}
	cout<<a[m];
	return 0;
}
