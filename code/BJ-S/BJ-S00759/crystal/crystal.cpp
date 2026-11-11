#include<bits/stdc++.h>
using namespace std;
long a[500010],b[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
    long long sum=0;
    int ans=0;
    for(int l=1,r=0;l<=n;l++){
        while(sum+1ll*(r-l+1)*b[r+1]<=m&&r<n) sum+=1ll*(r-l+1)*b[++r];
        ans=max(ans,r-l+1);
        if(r>=l) sum-=a[r]-a[l];
    }
    cout<<ans<<"\n";
    return 0;
}
//15:24 shuimeile!haoke
/*
16:07 gandepiaoliang
5 3
1 3 5 6 7
*/