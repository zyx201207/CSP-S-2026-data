#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,s[500005],a[500005],t,ans,l,r,mid,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(ll i = 1;i <= n;i++){
		s[i]=s[i-1]+a[i];
		l=1;
		r=i;
		t=1000000000;
		while(l<=r){
			mid=(l+r)/2;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m){
				r=mid-1;
				t=min(t,mid);
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-t+1);
	}
	cout<<ans;
	return 0;
} 
