#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long lxy[500010];
long long qzh[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    qzh[0]=0;
    qzh[1]=a[1];
    for(int i=2;i<=n;i++){
        qzh[i]=qzh[i-1]+a[i];
    }
    long long maxn=1;
    for(long long st=1;st<=n;st++){
        long long l=st,r=n;
        while(l<=r){
            long long mid=(l+r)/2;
            if(qzh[st-1]-qzh[mid-1]+(mid-st)*a[mid]>m){
                r=mid-1;
          //      cout<<"*";
           //     cout<<st<<" "<<mid<<" "<<qzh[st-1]-qzh[mid-1]+(mid-st)*a[mid]<<endl;
            }
            else{
    //            cout<<st<<" "<<mid<<" ";
    //            cout<<qzh[st-1]-qzh[mid-1]+(mid-st)*a[mid]<<endl;
                maxn=max(maxn,mid-st+1);
                l=mid+1;
            }
        }
    }
    cout<<maxn;
    return 0;
}
