#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=5e5+5;
ll n,m,a[inf],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=1,r=0,now=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,r-l+1);
		while(l<=r&&now+1ll*(a[i]-a[i-1])*(r-l+1)>m){
			now-=a[r]-a[l];
			l++;
		}
		if((l<r||r==0)&&now+1ll*(a[i]-a[i-1])*(r-l+1)<=m){
			now+=1ll*(a[i]-a[i-1])*(r-l+1);
		}
		r++;
	}
	cout<<ans;
	return 0;
}
