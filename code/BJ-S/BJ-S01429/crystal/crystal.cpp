#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,a[N],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++){
                scanf("%lld",&a[i]);
        }
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i!=n&&a[i+1]==a[i]) continue;// quchong
		int s=0,cnt=1;
		for(int j=i-1;j;j--){
			if(s+a[i]-a[j]>m) break;
			s+=(a[i]-a[j]);
			cnt++;
		}
        ans=max(ans,cnt);
	}
	cout<<ans;
        return 0;
}
