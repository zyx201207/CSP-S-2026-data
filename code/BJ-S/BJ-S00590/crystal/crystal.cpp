#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,m;
ll a[N],t[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(a[1]<0){
        ll x=a[1];
        for(int i=1;i<=n;i++){
            a[i]-=x;
        }
    }
    for(int i=2;i<=n;i++)
        t[i]=t[i-1]+a[i]-a[i-1];
    int maxl=0;
    int l=1,r=1;
    while(l<=n&&r<=n){
        if(t[r]-t[l]<=m){
            r++;
        }else{
            l++;
        }

        maxl=max(maxl,r-l+1);
    }
    cout<<maxl-1;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
