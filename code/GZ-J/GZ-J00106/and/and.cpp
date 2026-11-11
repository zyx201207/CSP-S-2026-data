//GZ-J00106 贵阳市清华中学 周子骏
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    ll n,m,ans=0;
    cin>>n>>m;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
    	cin>>a[i];
	}
	stable_sort(a.begin(),a.end());
	for(ll i=n-1;i>max(0ll,n-10);i--){
		for(ll j=i-1;j>max(0ll,n-10);j--){
			ll a1=a[i];
			for(ll k=1;k<m;k++){
				a1=a1&&a[j];j--;
				if(j<=max(0ll,n-10)){i--;j=i-1;
				}if(i<=max(0ll,n-10))break;}
    		ans=max(ans,a1);
			}
	}cout<<ans;
    return 0;

}
