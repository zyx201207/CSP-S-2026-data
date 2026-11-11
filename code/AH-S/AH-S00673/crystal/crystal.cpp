#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,m;
long long a[MAXN];
long long del[MAXN];
long long tot;
long long l,r;
long long maxans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        del[i]=a[i]-a[i-1];
    }
    l=r=2;
    tot=del[2];
    while(l<=r+1&&r<n){
        if(l<=r+1&&tot<=m){
            maxans=max(maxans,r-l+2);
        }
        while(tot<=m&&r<n){
            r++;
            tot=tot+(r-l+1)*del[r];
            if(l<=r+1&&tot<=m){
                maxans=max(maxans,r-l+2);
            }
        }
        tot=tot-a[r]+a[l-1];
        l++;
    }
    cout<<maxans;
    return 0;
}

