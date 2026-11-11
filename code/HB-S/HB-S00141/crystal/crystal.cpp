#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ddis tail-head+1
int read() {
    int ans=0,flag=1; char c=getchar();
    while(c<'0'||c>'9') {
		if(c=='-') flag=-1;
		c=getchar();
	}
    while(c>='0'&&c<='9') {ans=ans*10+c-'0'; c=getchar();}
    return ans*flag;
}
int n,m,a[500010],dis[500010],now,ans,head,tail;
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) dis[i]=a[i]-a[i-1];
    head=tail=1;
    for(int i=1;i<=n;i++) {
        if(now+(ddis-1)*dis[tail]>m) break;
        now+=(ddis-1)*dis[tail];
        tail++;
    }
    if(tail>n) {cout<<n<<'\n'; return 0;}
    // cout<<head<<" "<<tail<<'\n';
    ans=max(ans,ddis-1);
    for(;tail<=n;tail++) {
        now+=(ddis-1)*dis[tail];
        for(;head<=tail;head++){
            if(now<=m) break;
            now-=(a[tail]-a[head]);
        }
        ans=max(ans,ddis);
    }
    cout<<ans<<'\n';
    return 0;
}
