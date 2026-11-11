#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[200005],c[200005];
ll ans;
char b[200005],d[200005];
int pub(ll x,ll y,ll z,ll w){
	if(x>z){
		swap(x,z);
		swap(y,w);
	}
	if(y>=z&&y<=w)return y-z;
	else if(y>=z&&y>=w)return w-z;
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}for(int i=1;i<=n;i++){
		c[i]=a[n-i+1];
		d[i]=b[n-i+1];
	}int i=1,j=1;
	ll p=1,q=1;
	while(i<=n&&j<=n){
		int pu=pub(p,p+a[i],q,q+c[j]);
		if(b[i]!=d[j])ans+=pu;
		if(p+a[i]<q+c[j])p+=a[i++];
		else q+=c[j++];
	}cout<<(ans>>1);
	return 0;
}

