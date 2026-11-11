#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==n){
		ll ans=a[1];
		for(int i=1;i<=n;i++) ans&=a[i];
		cout<<ans
	}else if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}else if(m==2){
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else{
		sort(a+1,a+1+n);
		cout<<a[(n+1LL)/2];
	}
	return 0;
}
