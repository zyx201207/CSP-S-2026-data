#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,a[200010],sum=0,l=1,lim[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		lim[i]=lim[i-1]+a[i];
	}
	for(ll i=1,j=n;l<lim[n]/2+1;){
		if(c[i]!=c[j])
			sum+=min(a[i],a[j]);
		l+=min(a[i],a[j]);
		a[i]-=min(a[i],a[j]);
		a[j]-=min(a[i],a[j]);
		if(l>lim[i]) i++;
		if(lim[n]-l+1<lim[j-1]+1) j--;
	}
	cout<<sum;
	return 0;
}
