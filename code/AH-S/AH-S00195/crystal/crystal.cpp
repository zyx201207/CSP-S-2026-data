#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N];
bool check(int k){
    for(int i=k;i<=n;i++){
        int s=0;
        if(a[i]*k-(sum[i]-sum[i-k])<=m) return true;
    }
    return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<r){
        int mid=l+r>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
	}
	cout<<ans;
	return 0;
}
