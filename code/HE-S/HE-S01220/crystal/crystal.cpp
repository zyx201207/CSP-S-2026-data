#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005],into_use=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=1e13;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			ll check=0;
			ll ans=1;
			while(ans<i){
				if(check+(a[i]-a[i-ans-1])>m){
					break;
				}
				check+=a[i]-a[i-ans-1];
				ans++;
			}
			into_use=max(into_use,ans);
		}
	}
	cout<<into_use;
	return 0;
} 
