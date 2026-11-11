#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005],c[500005],d[500005],ans=1;
__int128 mm,nn,tt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(n>5000){
        long long t=a[2]-a[1];
        mm=m,tt=t;
        __int128 l=1,r=n,mid;
        while(l<r){
            mid=(l+r+1)/2;
            if((tt*mid*(mid-1)/2)<=m)l=mid;
            else r=mid-1;
        }
        long long ll=l;
        cout<<ll;
        return 0;
    }
    for(int i=1;i<n;i++)b[i]=a[i+1]-a[i];
    for(int i=1;i<n;i++){
        for(int j=i;j<n;j++){
                c[j+1]=0;d[j+1]=0;
            for(int k=j;k>=i;k--)c[k]=c[k+1]+b[k];
            for(int k=j;k>=i;k--)d[k]=d[k+1]+c[k];
            if(d[i]<=m)ans=max(ans,(long long)(j-i+2));
        }
    }
    cout<<ans;
    return 0;
}
//AFO-2026.10.31
//bye
