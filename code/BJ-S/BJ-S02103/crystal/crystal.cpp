#include <bits/stdc++.h>
using namespace std;
int a[500010];
long long n,m,ma;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma+=a[i];
    }
    ma/=n;
    while(m>0){
        for(int i=1;i<=n;i++){
            if(a[i]<ma){
                a[i]+=1;
                break;
            }
            if(i==n){
                ma+=1;
            }
        }
        m=m-1;
    }
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            ans+=1;
        }
    }
    cout<<ans+1;
    return 0;
}
