#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,l,cm,ca,ans=INT_MIN;
    cin>>n>>m;
    int a[n+3];
    bool ok=true;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1&&i!=2&&a[i-1]-a[i-2]!=a[i]-a[i-1])ok=false;
    }
    if(ok){
        int cha=a[2]-a[1];
        for(int i=cha;i<=n;i+=cha){
            m-=i;
            if(m<=0){
                cout<<i/cha;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }
    int l1=0;
    sort(a+1,a+n+1);
    for(long long i=a[2];i<=a[n];i++){
        cm=0;
        ca=0;
        for(l=2;l<=n;l++){
            if(a[l]>i)break;
        }
        if(l==l1)continue;
        for(long long j=l;j>=1;j--){
            cm+=(i-a[j]);
            ca++;
            if(cm>m){
                ans=max(ans,ca-1);
                l1=l;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
