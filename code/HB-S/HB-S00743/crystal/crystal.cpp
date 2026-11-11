#include<bits/stdc++.h>
using namespace std;
int n,l,r,mid;
long long m,a[500005],b[500005];
int mx=-1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
    for(int i=n;i>0;i--){
        l=1,r=i;
        while(l<r){
            mid=(l+r)>>1;
            // cerr<<"l="<<l<<" mid="<<mid<<" r="<<r<<"  ";
            if(a[i]*(long long)(i-mid+1)-(b[i]-b[mid-1])<=m){
                // cerr<<"C\n";
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        mx=max(mx,i-l+1);
        // cerr<<"# "<<i<<" Completed, answer="<<i-l+1<<"\n";
    }
    cout<<mx;
}