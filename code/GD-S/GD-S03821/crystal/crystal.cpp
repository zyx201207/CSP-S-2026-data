#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int const N=5e5+5;
ll a[N],m,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	int n;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=2;i<=n;i++){
		ll cnt=0;
		for(int j=i-1;j>0;j--){	
			int t=a[i]-a[j];
			if(t<0)t-=(2*t);		
			cnt+=t;
			if(cnt>m)break;
			if(cnt<=m)ans=max(ans,ll(i-j+1));						
		}
	}cout<<ans;
	return 0;
}
