#include<algorithm>
#include<iostream>
using namespace std;
#define int long long
const int maxn=5e5+10,inf=1e17;
int n,m,a[maxn],s[maxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int pos=1;
    for(int i=1;i<=n;i++){
        int l=1,r=i-1,ans=i;
        while(l<=r){
            int mid=l+r>>1;
            int cnt=(i-mid);
            if(cnt*a[i]-s[i-1]+s[mid-1]<=m)ans=mid,r=mid-1;
            else l=mid+1;
        }
        pos=max(pos,i-ans+1);
    }
    cout<<pos<<'\n';
}