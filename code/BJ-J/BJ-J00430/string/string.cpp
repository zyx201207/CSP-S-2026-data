#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,ans=0;
    cin>>n;
    long long a[n+10];
    char c[n+10];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long x=1,y=n;
    while(x<=y){
        long long now=min(a[x],a[y]);
        if(c[x]==c[y]){
            if(a[x]==now)x++;
            else a[x]-=now;
            if(a[y]==now)y--;
            else a[y]-=now;

        }
        else{
            ans+=now;
            if(now==a[x])x++;
            else a[x]-=now;
            if(now==a[y])y--;
            else a[y]-=now;
        }
    }
    cout<<ans;
    return 0;
}
