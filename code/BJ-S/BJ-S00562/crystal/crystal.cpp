#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500005],l,r,len,val,maxn=-1;
bool cmp(long long x,long long y){
    return x<y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    l=n-1,r=n,len=2,val=a[r]-a[l];
    while(1){
        if(val<=m){
            maxn=max(maxn,len);
        }
        if(l==1){
            break;
        }
        if(val<=m){
            l--;
            val+=a[r]-a[l];
            len=r-l+1;
        }
        else{
            r--;
            len=r-l+1;
            val-=(len)*(a[r+1]-a[r]);
        }
    }
    cout<<maxn;
    return 0;
}