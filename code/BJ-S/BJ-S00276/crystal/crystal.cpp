#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N];
ll s[5005][5005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll m;
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            flag=0;
        }
    }
    sort(a+1,a+n+1);
    int ans=0;
    if(n<=5000){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                s[i][j]=s[i][j-1]+((a[j]-a[j-1])*(j-i));
            }
        }   
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(s[i][j]>m) continue;
                else{
                    ans=max(ans,j-i+1);
                }
            }
        }
        cout<<ans;
    }
    else{
        if(flag){
            int ans=0;
            for(int i=0;i<=n-1;i++){
                if((1ll*(1+i)*i)/2<=m){
                    ans++;
                }
            }
            cout<<ans;
        }
        else{
            ll ch=a[2]-a[1];
            int ans=0;
            for(int i=0;i<=n-1;i++){
                if((1ll*(1+i)*i)/2*ch<=m){
                    ans++;
                }
            }
            cout<<ans;
        }
    } 
    return 0;
}