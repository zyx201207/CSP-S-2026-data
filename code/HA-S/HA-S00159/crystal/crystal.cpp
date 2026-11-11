#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],s[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		s[i]=a[i]-a[i-1];
		s[i]+=s[i-1];
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			ll sum=0,cnt=1;
			for(int j=i-1;j>=1;j--){
				if(sum+(a[i]-a[j])>m){
					break;
				}
				cnt++;
				sum+=(a[i]-a[j]);
			}
			ans=max(ans,cnt);
		}
	}else{
		ll sum=0;
		for(ll l=1,r=1;r<=n;r++){
			while(l<=r&&sum+(a[r]-a[r-1])*(r-l)>m){
				sum-=(a[r]-a[l]);
				l++;
			}
			sum+=(a[r]-a[r-1])*(r-l);
			ans=max(ans,(r-l+1));
		}
	}
	cout<<ans;
	return 0;
} 
