#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],b[N];
int ans=1;
bool cmp(int x,int y){
    return x>y;
}
int check(int x){
    int l=x,r=n,res=0;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(a[x]*(mid-x+1)-b[mid]+b[x-1]<=m){
            l=mid+1;
            res=mid;
        }else r=mid-1;
    }
    return res-x+1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i];
    for(int i=1;i<=n;i++)
        ans=max(ans,check(i));
    cout<<ans<<endl;
    return 0;
}
