#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;
ll m;
ll a[N];
bool check(int x){
    ll cost=0,res=LLONG_MAX;
    for (int i=1;i<=x;i++){
        cost+=a[x]-a[i];
    }
    res=min(res,cost);
    int i=1,j=x;
    while (j<n){
        cost-=a[j]-a[i];
        cost+=(x-1)*(a[j+1]-a[j]);
        res=min(res,cost);
        i++;
        j++;
    }
    return (res<=m);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n;
    while (l<r){
        int mid=(l+r+1)>>1;
        if (check(mid)){
            l=mid;
        }
        else {
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}
