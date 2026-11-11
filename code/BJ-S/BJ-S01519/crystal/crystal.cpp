#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define endl '\n'
const int N=5e5+10;
int a[N],q[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    fr(i,1,n)cin >> a[i];
    sort(a+1,a+n+1);
    fr(i,1,n)q[i]=q[i-1]+a[i];
    int ans=0;
    fr(i,1,n){
        int l=1,r=i,res=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(q[i]-q[mid-1])<=m)res=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout << ans << endl;
    return 0;
}
