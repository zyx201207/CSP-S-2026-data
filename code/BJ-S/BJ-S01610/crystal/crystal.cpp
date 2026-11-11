#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=5e5+5;

int n;
ll m,a[maxn],s[maxn];
int ans=1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=2;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            if((i-mid+1)*a[i]-s[i]+s[mid-1]<=m)r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-r+1);
    }
    cout<<ans;
    return 0;
}
