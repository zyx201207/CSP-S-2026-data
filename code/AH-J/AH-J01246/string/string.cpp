#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
ll a[N],n;
char c[N];
ll strg(){
	ll l=1,r=n,ans=0;
	while(l<r){
		//cout<<l<<' '<<r<<' '<<a[l]<<' '<<a[r]<<' '<<c[l]<<' '<<c[r]<<endl;
		ll t=min(a[l],a[r]);
		if(c[l]!=c[r])ans+=min(a[l],a[r]);
		if(a[l]>1&&a[r]>1){
			a[l]-=t,a[r]-=t;
			continue;
		}
		bool lb=1,rb=1;
		if(a[l]<=1)l++,lb=0;
		if(a[r]<=1)r--,rb=0;
		if(lb)a[r]--;
		if(rb)a[l]--;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	cout<<strg();
	/*ll i=0,j=0,l=1,r=n,h=0,k=0;
	for(;l<=r;){
		h=i,k=j;
		if(c[l]!=c[r]){
			ll t=min(a[l]-i+h,a[r]-j+k);
			ans+=t;
			i+=t,j+=t;
			if()
		}
		if(i>j){
			j+=a[r];
			r--;
			continue;
		}
		else if(i<j){
			i+=a[l];
			l++;
			continue;
		}
		else{
			i+=min(a[l],a[r]);
			j+=min(a[l],a[r]);
			l++,r--;
		}
		cout<<i<<' '<<j<<' '<<l<<' '<<r<<endl;
	}*/
	return 0;
} 
