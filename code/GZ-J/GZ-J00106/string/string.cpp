//GZ-J00106 贵阳市清华中学 周子骏
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,ans=0;cin>>n;
    vector<ll>a(n+1);
    vector<char>b(n+1);
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}ll i=1,r=n;
	while(i<=r){
		if(b[i]!=b[r])ans+=min(a[i],a[r]);
		if(a[i]>a[r]){
				a[i]-=a[r];
				r--;
		}else if(a[i]<a[r]){
				a[r]-=a[i];
				i++;
		}else {
		r--;i++;
		}
		}
	cout<<ans;
    return 0;

}
