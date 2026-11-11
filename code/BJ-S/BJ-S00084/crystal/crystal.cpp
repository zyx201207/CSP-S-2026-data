#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long m,a[500005],b[500005],t,mid,cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=a[i]-a[1];
    }
    //
    l=1;
    r=n+1;
    while(l<r-1){
        mid=(l+r+1)/2;
        for(int i=1;i<=n-mid+1;i++){
            t=0;
            for(int j=i;j<i+mid;j++){
                cnt=0;
                for(int k=i;k<i+mid;k++){
                    if(b[k]-b[j]>0){
                        cnt+=b[k]-b[j];
                    }
                    else{
                        cnt+=b[j]-b[k];
                    }
                }
                if(cnt<=m){
                    t=1;
                    break;
                }
            }
            if(t==1)break;
        }
        if(t==1){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<l;
    return 0;
}
