#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int a[N];
int n,m;
int s[N];

bool check(int x,int d) {
    int tot=d-x+1;
    int num=s[d]-s[x-1];
    int t=tot*a[d]-num;
    return t<=m;
}

signed main() {
    freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++) {
        int L=1,R=i;
        while(L<=R) {
            int mid=L+R>>1;
            if(check(mid,i)) {
                R=mid-1;
                ans=max(ans,i-mid+1);
            }
            else L=mid+1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}