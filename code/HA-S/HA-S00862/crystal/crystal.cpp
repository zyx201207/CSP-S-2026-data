#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],m,ans,lst,pos,n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	//for(int i=1;i<n;i++)c[i]=a[i+1]-a[i];
	//for(int i=1;i<=n;i++)cout<<c[i]<<" ";
	pos=n;
	for(ll i=n-1;i;i--){
		ll sum=lst+a[n]-a[i];
		if(sum>m)break;
		lst=sum;
		pos=i;
	}
	//cout<<pos;
	//cout<<lst;
	ans=n-pos+1;
	for(ll i=n-1;i;i--){
		lst=lst-(i-pos+1)*(a[i+1]-a[i]);
		for(ll j=pos-1;j;j--){
			lst+=a[i]-a[j];
			if(lst>m){
				lst-=a[i]-a[j];
				break;
			}
			pos=j;
		}
		ans=max(ans,i-pos+1);
	}
	printf("%lld",ans);
	return 0;
}
