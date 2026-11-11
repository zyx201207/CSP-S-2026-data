#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX=2*1e5+5;
ll n,cnt,a[MAX];
char c[MAX];
ll find(ll m){
	ll l=1,r=n,ans=-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(a[mid]>=m){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a[i]+=(a[i-1]-1);
	}
	for(int i=1;i<=n;i++){
		int ni=find(a[n]-a[i]);
		int nj=find(a[n]-a[i-1]+1);
		if(c[ni]!=c[i]) cnt+=(a[ni]-a[n]+a[i]+1);
		if(c[nj]!=c[i]) cnt+=(a[n]-a[i-1]+2-a[nj-1]);
		for(int j=ni+1;j<=nj-1;j++)
			if(c[j]!=c[i])
				cnt+=(a[j]-a[j-1]+1);
	}
	cout<<cnt/2;
	return 0;
}
