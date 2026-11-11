#include<iostream>
using namespace std;
typedef long long ll;
ll n,m,a[200010],maxn,get5=0x3f3f3f3f3f3f3f3f;
void get10(){
	ll maxn=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(a[i]==a[j]) continue;
			maxn=max(maxn,a[i]&a[j]);
		}
	}
	cout<<maxn;
}
void get10again(){
	ll maxn=0;
	for(ll i=1;i<=n;i++){
		maxn=max(maxn,get5|a[i]);
	}
	cout<<maxn;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		get5&=a[i];
	}
	//能混多少是多少
	if(m==1) cout<<maxn;
	if(m==n) cout<<get5;
	if(m==2) get10();
	if(m==n-1) get10again();
    return 0;
}
