#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long kk[n+5];
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>kk[i];
    }
    long long cc=kk[2]-kk[1];
    bool fl=true;
    for(int i=2;i<n;i++){
        if(cc!=kk[i+1]-kk[i]){
            fl=false;
        }
    }
    if(fl){
        int ans1=1;
        for(int i=1;i<=n;i++){
            if(m>=i*cc){
                ans1++;
                m-=i*cc;
            }
        }
        cout<<ans1;
        return 0;
    }
    sort(kk+1,kk+n+1);
    int ans=1;
    for(int i=n;i>1;i--){
        int ans1=1,ml=m;
        for(int j=i-1;j>0;j--){
            if(kk[i]-kk[j]<=ml){
                ml-=kk[i]-kk[j];
                ans1++;
            }
        }
        ans=max(ans,ans1);
    }
    cout<<ans;
    return 0;
}
