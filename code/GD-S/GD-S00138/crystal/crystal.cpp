#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int now=0,res=0,cost=0;
    int l=1,r=1;
    for(;r<=n;r++){
        cost+=now*(a[r]-a[r-1]);
        now++;
        while(cost>m){
            cost-=a[r]-a[l];
            l++;
            now--;
        }
        res=max(res,now);
    }
    cout<<res;
    return 0;
}