#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005],dc,maxx=0,okd=0,okp=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i]=a[i]-a[i-1];
        //cout<<d[i]<<" ";
        if(a[i]!=i)okp=1;
    }
    //cout<<d[2]<<endl;
    for(int i=1;i<n;i++){
        if(d[i]!=d[i+1])okd=1;
    }
    if(okp==0){
        int s=0;
        for(int i=1;i<=n-1;i++){
            s+=i;
            if(s>m){
                cout<<i;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }else if(okd==0){
        int s=0;
        for(int i=d[2];i<=n-1;i+=d[2]){
            s+=i;
            if(s>m){
                cout<<i;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int s=0,ans=0;
        for(int j=i;j>=1;j--){
            s+=a[i]-a[j];
            if(s<=m)ans++;
            else break;
        }
        if(ans>maxx)maxx=ans;
    }
    cout<<maxx;
    return 0;
}
