#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;

int n,m;
int a[N],s[N];
int b[N];

int check0(int pos){
    int l=0,r=pos-1;
    if(r<=0) return 1;
    int res=l;
    while(l<=r){
        int mid=l+r>>1;
        int lh=-1*(s[pos-1]-s[pos-mid-1]-mid*a[pos]);
        if(lh<=m){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return res+1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++) s[i]=a[i]+s[i-1];
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,check0(i));
    }

    cout<<ans<<"\n";
    return 0;

}
