#include<bits/stdc++.h>
#define ll long long
#define FR(a,b,c) for(ll a=b;a<=c;++a)
#define RF(a,b,c) for(ll a=b;a>=c;--a)
using namespace std;
const int N=2e5+7;
ll n,a[N],sl,sr,sum,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	FR(i,1,n){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	ll mid=sum/2;
	ll l=1,r=n;
	while(l<=r){
		if(sl+a[l]<=mid&&sr+a[r]<=mid){
			int x=1;
			if(c[l]==c[r])x=0;
			ans+=min(a[l],a[r])*x;
			if(a[l]>a[r]){
				sr+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				sl+=a[l];
				a[r]-=a[l];
				l++;
			}else if(a[l]==a[r]){
				sr+=a[r];
				sl+=a[l];
				r--;
				l++;
			}
		}else{
			int x=1;
			if(c[l]==c[r])x=0;
			if(sl+a[l]>mid&&sr+a[r]>mid){
				break;
			}else if(sl+a[l]>mid){
				ans+=a[r]*x;
				break;
			}else if(sr+a[r]>mid){
				ans+=a[l]*x;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
