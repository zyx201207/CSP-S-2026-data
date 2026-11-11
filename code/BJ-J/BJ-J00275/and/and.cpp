#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m,a[MAXN],ans;
int now;
bool cmp(int x,int y){
    if((x&now)!=(y&now)) return (x&now)>(y&now);
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=30;i>=0;i--){
        now=(1<<i);
        sort(a+1,a+n+1,cmp);
        int l=1,r=n,res=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[mid]&now){
                res=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        if(res>=m){
            n=res;
            ans+=now;
        }
    }
    cout<<ans;
    return 0;
}
