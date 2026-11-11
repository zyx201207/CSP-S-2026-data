#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m;
ll a[N];
ll maxn=1;
void cha(int p){
	ll ans=1,sh=m;
	for(int i=p-1;i>0;i--){
		sh=sh-a[p]+a[i];
		if(sh>=0){
			ans++;
		}else{
			break;
		}
	}
	maxn=max(maxn,ans);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool kkk=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			kkk=1;
			break;
		}
	}
	if(kkk){
		sort(a+1,a+n+1);
		for(int i=n;i>1;i--){
			cha(i);
		}
		cout<<maxn;
	}else{
		ll k1=1,k2=k1+1;
		while((k1*k2)/2 <= m){
			k1++;
			k2++;
		}
		cout<<k1;
	}
	return 0; 
}
