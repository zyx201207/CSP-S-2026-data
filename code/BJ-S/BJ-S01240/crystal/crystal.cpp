#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,l,r;
ll m,a[N],tot;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        tot=0;
        for(int i=1;i<=n&&a[i]<a[mid];i++){
            tot+=a[mid]-a[i];
        }
        if(tot<=m)l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}
