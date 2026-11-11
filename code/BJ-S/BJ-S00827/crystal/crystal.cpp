#include <bits/stdc++.h>
#define int long long
using namespace std;
int p[500005];
int a[500005];
int n,m;
bool check(int x){
    for(int i=x;i<=n;i++){
        int mm=p[i]-p[i-x];
        int mmm=a[i]*x-mm;
        if(mmm<=m) return true;
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        p[i]=a[i]+p[i-1];
    }
    int l=1,r=n;
    while(l<=r){
        int mid=((l+r)/2);
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
        cout<<l<<" "<<r<<" "<<mid<<endl;
    }
    cout<<l-1;
    return 0;
}