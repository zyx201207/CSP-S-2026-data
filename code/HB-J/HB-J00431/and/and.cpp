#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005],x;
bool cmp(ll a,ll b){return a>b;}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    x=a[1];
    if(m==n){
    for(int i=2;i<=n;i++){cin>>a[i];x&=a[i];}}
    if(m==1){
            for(int i=2;i<=n;i++)cin>>a[i];
        sort(1+a,1+n+a);
        cout<<a[n];
    }else {

      for(int i=2;i<=n;i++)cin>>a[i];
    sort(1+a,1+a+n);
    x=a[n];
    for(int i=n-1;i>=n-m+1;i--)x&=a[i];
    }

    cout<<x;
    return 0;
}

