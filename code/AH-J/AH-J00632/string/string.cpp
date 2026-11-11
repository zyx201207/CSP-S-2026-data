#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st{
	char c;
	ll s;
}a[400000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll sum=0;
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i].s);
		cin>>a[i].c;
	}
	ll i=1,j=n;
	while(i<j){
		ll k=min(a[i].s,a[j].s);
		if(a[i].c!=a[j].c)	sum+=k;
		a[i].s-=k;
		a[j].s-=k;
		if(a[i].s==0)	i++;
		if(a[j].s==0)	j--;
	}
	cout<<sum;
	return 0;
}
