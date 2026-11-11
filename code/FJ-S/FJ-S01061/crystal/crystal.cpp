#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,m;
ll a[N],b[N],c[N],ans,last;
bool flag;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	last=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(last!=a[i]-a[i-1]) flag=1;
	}
	if(flag==0){
		ll cnt=0;
		for(int j=n-1;j>=1;j--){
			cnt+=a[n]-a[j];
			if(cnt<=m){
				ans=max(ans,(ll)n-j+1);
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			ll cnt=0;
			for(int j=i-1;j>=1;j--){
				cnt+=a[i]-a[j];
				if(cnt<=m){
					ans=max(ans,(ll)i-j+1);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
