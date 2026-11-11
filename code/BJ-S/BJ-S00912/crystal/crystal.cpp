#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+13;
int n,m;
int a[maxn],s[maxn];
int work(int id){
    int l=1,r=id;
    while(l<r){
        int mid=(l+r)/2+1;
        int summ=s[id]-s[id-mid];
        if(a[id]*mid-summ<=m) l=mid;
        else r=mid-1;
    }
    return l;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,work(i));
    }
    cout<<ans;
    return 0;
}
