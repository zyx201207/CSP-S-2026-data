#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
ll n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	ll l,r,s=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l=a[1],r=a[n];
	if(l==r){
		cout<<n;
		return 0;
	}
	while(l<r){
		ll mid=(l+r)/2,ans=0,tot=0;
		for(int i=1;i<=n;++i){
			if(a[i]<=mid){
				ans+=(mid-a[i]);
				tot++;
			}
		}
		if(ans>m) r=mid-1;
		else{
			if(l==mid){
				ll ans1=0,tot1=0;
				for(int i=1;i<=n;++i){
					if(a[i]<=(mid+1)){
						ans1+=((mid+1)-a[i]);
						tot1++;
					}
				}
				if(ans1<=m){
					tot=max(tot,tot1);
				}
				l=mid+1;
			}
			else l=mid;
			s=max(s,tot);
		}
	}
	cout<<s;
	return 0;
} 
