#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int b[500005];
int c[500005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    b[0]=0;
    for(int i=1;i<=n;i++){
        b[i]=a[i]-a[i-1];
        c[i]=c[i-1]+b[i];
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        int cost=0;
        for(int i=1;i<mid;i++){
            cost+=i*b[i+1];
        }
        bool flag=0;
        for(int i=1;i<=n-mid+1;i++){
            if(cost<=m){
                flag=1;
                break;
            }
            cost-=(c[i+mid-1]-c[i]);
            cost+=mid*b[i+mid];
        }
        if(flag) l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
}
//programing 20mins
//debug 30mins
//O(logm*n+n*logn+2*n)->4e7
