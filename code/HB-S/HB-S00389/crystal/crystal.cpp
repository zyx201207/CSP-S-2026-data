#include <bits/stdc++.h>
using namespace std;
int n,m,mn=INT_MIN,mn1=INT_MAX,mx=INT_MIN,l,num;
int a[114514];
int b[114514];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)mn1=min(mn1,a[i]);
    if(mn1<=0){
        for(int i=1;i<=n;i++){
            a[i]+=abs(mn1)+1;
        }
    }
    for(int i=1;i<=n;i++)b[a[i]]++;
    for(int i=1;i<=n;i++)mn=max(mn,a[i]);
    for(int i=1;i<=mn;i++)mx=max(mx,b[i]);
    for(int i=1;i<=mn;i++){
        if(b[i]==mx){
            mx=i;
            break;
        }
    }
    for(int i=mx;i>=1;i--){
        if(m>=b[i]*(mx-i)){
            m-=b[i]*(mx-i);
            num+=b[i];
        }
        else if(m>=mx-i){
            for(int j=1;j<=b[i];j++){
                if(m>=mx-i){
                    m-=mx-i;
                    num++;
                }
            }
        }
    }
    cout<<num;
    return 0;
}
