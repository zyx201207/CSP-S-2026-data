#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=5e5+10;
ll a[N];
int n;
ll m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll cnt=0,ans=0;
	for(ll l=1,r=1;r<=n;){
		while(cnt>m){
			cnt-=a[r]-a[l++];
		}
		ans=max(ans,r-l+1);
		cnt+=(a[r+1]-a[r])*(r-l+1);
		r++;
	}
	cout<<ans<<endl;
	return 0;
} 
