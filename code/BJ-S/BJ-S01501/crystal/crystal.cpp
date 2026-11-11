#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],s[N];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int maxx=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r+1)/2;
            if(a[i]*mid-s[i]+s[i-mid]<=m) l=mid;
            else r=mid-1;
        }
        maxx=max(maxx,l);
    }
    cout<<maxx;
    return 0;
}
