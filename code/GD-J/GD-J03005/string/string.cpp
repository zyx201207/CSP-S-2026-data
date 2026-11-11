#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ma=2e5+5;
ll a[ma];
char c[ma];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	ll l=1,r=n,cntl=a[1],cntr=a[n],ans=0;
	while(l<r){
//		cout<<a[l]<<" "<<a[r]<<"\n";
		if(cntl>sum/2){
			a[l]=max(0ll,a[l]-cntl+sum/2);
			cntl=sum/2;
		}
		if(cntr>sum/2){
			a[r]=max(0ll,a[r]-cntr+sum/2);
			cntr=sum/2;
		}
		ll x=a[l],y=a[r];
		if(c[l]!=c[r])ans+=min(x,y);
		a[l]-=min(x,y);
		a[r]-=min(x,y);
		if(!a[l]&&cntl<sum/2)cntl+=a[++l];
		if(!a[r]&&cntr<sum/2)cntr+=a[--r];
		if(!a[l]&&!a[r]&&cntl==sum/2&&cntr==sum/2)break;
	}
	cout<<ans;
	return 0;
}
/*
*/
