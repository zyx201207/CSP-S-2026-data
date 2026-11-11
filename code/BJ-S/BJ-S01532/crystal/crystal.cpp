#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],b[500009],c[500009],maxx,ans;
bool tb=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(i>2)
            tb=tb&&a[i]-a[i-1]==a[i-1]-a[i-2];
        maxx=max(a[i],maxx);
    } 
    if(tb){
        for(long long i=2;i<=n;i++){
            if((a[i]-a[1])*n/2<=m){
                cout<<i;
                return 0;
            }
        }
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        b[i]=maxx-a[i];
        c[i]=b[i]+c[i-1];
        for(long long j=0;j<i;j++){
            if(c[i]-c[j]-(maxx-a[i])*(i-j)<=m){
                ans=max(ans,i-j);
            }
        }
    } 
    cout<<ans;
}