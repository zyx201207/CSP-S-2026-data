#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1000009];
char c[1000009];
int xj(pair<int,int> x,pair<int,int> y){
    int l,r;
    l=max(x.first,y.first),r=min(x.second,y.second);
    if(l>r){
        return 0;
    }
    return r-l+1;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int zz;
    zz=n+1;
    int sum;
    sum=0;
    int gz;
    gz=0;
    int ans;
    ans=0;
    for(int i=1;i<=n;i++){
            if(c[zz]!=c[i])
        ans+=xj({gz+1,gz+a[i]},{sum-a[zz]+1,sum});
        while(zz>1&&sum<=gz+a[i]){
            --zz;
            sum+=a[zz];
            if(c[zz]!=c[i])
        ans+=xj({gz+1,gz+a[i]},{sum-a[zz]+1,sum});
        }
        gz+=a[i];
    }
    cout<<ans/2;
    return 0;
}
