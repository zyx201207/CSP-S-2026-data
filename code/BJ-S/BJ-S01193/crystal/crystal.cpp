#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N];
int main(){
    ios::sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	int n,m;
	ll d=0;
	cin>>n>>m;
	bool f=1;
	for(int i=1; i<=n; i++){
        cin>>a[i];
        d=a[2]-a[1];
        if((a[i]-a[i-1])!=d && i>1) f=0;
	}
	if(f){
        int x=sqrt(m*2);
        int ans=0;
        m/=d;
        for(int i=1; i<=x; i++){
            if(i*(i+1)/2<=m){
                ans=max(ans,i);
            }
        }
        cout<<ans+1;
        return 0;
	}
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=n; i>=ans; i--){
        ll s=0,cnt=1;
        for(int j=i-1; j>=1; j--){
            s+=(a[i]-a[j]);
            if(s<=m) cnt++;
            else{
                ans=max(ans,cnt);
                continue;
            }
            ans=max(ans,cnt);
        }
	}
	cout<<ans;
	return 0;
}
