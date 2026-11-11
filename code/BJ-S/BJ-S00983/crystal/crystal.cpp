#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e8+8;

int n,m;
int a[N],b[N];


signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    b[1]=0;
    int ans=1,sum=0;
    for (int i=1;i<=n;i++){
        if (a[i]==a[i-1] || a[i]==a[i+1]) sum++;
        if (a[i+1]!=a[i]){
            sum=0;
            ans=max(ans,sum);
        }
    }
    for (int i=2;i<=n;i++){
        int l=0,r=i-1;
        b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
        if (b[i]<=m) ans=max(ans,i);
        while(l<=r && 0<=l && r<i){
            int mid=(l+r)/2;
            int f=b[i-1]+(a[i]-a[i-1])*(i-1)-b[mid];
            if (f<=m){
                ans=max(ans,i-mid);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
    }
    cout<<ans;
}
