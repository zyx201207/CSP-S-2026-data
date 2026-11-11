#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll a[N],n,i,ans=1,l,r,s,sum[N],k,S;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
    sort(a+1,a+n+1);
    l=1,r=1;
    S=a[1];
    while(r<=n&&l<=r){
		if((r-l+2)*a[r+1]-S-a[r+1]<=k) S+=a[++r];
		else S-=a[l++];
		ans=max(ans,r-l+1);
	}
    cout<<ans;
    return 0;
}
