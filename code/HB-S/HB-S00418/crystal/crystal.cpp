#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    ll sum=0,ans=0;
    for(int i=0;i<n;i++)cin>>a[i];
    ll d=a[1]-a[0];
    for(int i=0;i<n;i++){
        if(sum+a[i]-d<=m){
            sum+=a[i]-d;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
