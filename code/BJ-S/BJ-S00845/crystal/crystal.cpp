#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int pfix[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) pfix[i]=pfix[i-1]+a[i];
    int l=1,ans=0;
    for(int r=1;r<=n;r++){
        while(a[r]*(r-l+1)-(pfix[r]-pfix[l-1])>m) l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
