#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans=0,tot=0,l=1,r=1,cnt=0;
long long a[500005],b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    while(l<=n&&r<=n){
        cnt+=a[r];
        r++;
        tot++;
        while(a[r-1]*tot-cnt>m){
            cnt-=a[l];
            l++,tot--;
        }
        ans=max(ans,tot);
    }
    cout<<ans;
    return 0;
}
