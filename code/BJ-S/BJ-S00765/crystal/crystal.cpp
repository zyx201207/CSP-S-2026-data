#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],cnt=0,pd[500005],ans=1;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        pd[i]=a[i]-a[i-1];
    }
    int l=0,r=0;
    while(r<n){
		if(l>r) r=l,cnt=0;
		if(r-l+1>ans) ans=r-l+1;
		if(cnt+(r-l+1)*pd[r+1]<=m){
			cnt+=(r-l+1)*pd[r+1];
			r++;
			}
		else {
			cnt-=(a[r]-a[l]);
			l++;
			}
		}
    cout<<ans;
    return 0;
}
