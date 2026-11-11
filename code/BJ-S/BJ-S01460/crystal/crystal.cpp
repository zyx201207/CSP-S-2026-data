#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sa[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sa[i]=a[i]-a[i-1];
    }
    for(int i=n;i>=1;i--){
        sa[i]=sa[i+1]+sa[i];
    }
    for(int i=1;i<=n;i++){
        sa[i]=sa[i+1];
    }
    for(int i=n;i>=1;i--){
        sa[i]=sa[i+1]+sa[i];
    }
    for(int i=1;i<=n;i++){
        //cout<<sa[i]<<endl;
        for(int j=i+1;j<=n;j++){
            int num=sa[i]-sa[j]-(a[n]-a[j])*(j-i);
            //cout<<i<<" "<<j<<" "<<num<<endl;
            if(num<=m){
                ans=max(ans,(long long)(j-i+1));
            }
        }
    }
    cout<<ans;
    return 0;
}
