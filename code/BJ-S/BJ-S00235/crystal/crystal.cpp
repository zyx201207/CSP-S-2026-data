#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n,m,a[500005],s[500005],ans,aflag=1,bflag=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i],s[i]=s[i-1]+a[i];
        if(a[i]!=i)aflag=0;
        if(i>=3){
            if(a[i]-a[i-1]!=a[i-1]-a[i-2])bflag=0;
        }
    }
    if(aflag==1){
        for(int i=1;i<=n;i++){
            if((i*(i-1)/2<=m)&&(i*(i-1)/2>=0))ans=max(ans,i);
        }
        cout<<ans;
        return 0;
    }
    if(bflag==1){
        for(int i=1;i<=n;i++){
            if((a[i]*i-((a[1]+a[i])*i/2)<=m)&&(a[i]*i-((a[1]+a[i])*i/2)>=0))ans=max(ans,i);
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    int l=1,r=2;
    while(l<r){
        if((a[r+1]*r-(s[r]-s[l-1]))<=m)ans=max(ans,r-l+2),r++;
        else l++;
    }
    cout<<ans;
    return 0;
}