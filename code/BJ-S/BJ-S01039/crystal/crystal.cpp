#include<bits/stdc++.h>
using namespace std;
int n,l,r,mid,a[500007];
long long m,t;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n>5000){
        long long c=a[2]-a[1];
        m=m/c*2;
        int i=1;
        for(i;i*(i-1)<=m;i++){}
        cout<<i-1;
        return 0;
    }
    r=n;
    while(l<r){
        mid=(l+r)>>1,t=m;
        bool f=true;
        for(int i=1;i<mid;i++){
            t-=a[mid]-a[i];
            if(t<0){
                f=false;
                break;
            }
        }
        if(f){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    cout<<l-1;
    return 0;
}
