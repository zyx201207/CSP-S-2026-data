#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int MAXN=5e5+5;
int n,m,a[MAXN],s[MAXN];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,res;
        while(l<=r){
            int mid=l+r>>1;
            int cost=(i-mid+1)*a[i]-(s[i]-s[mid-1]);
            if(cost<=m)res=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans<<endl;
    return 0;
}