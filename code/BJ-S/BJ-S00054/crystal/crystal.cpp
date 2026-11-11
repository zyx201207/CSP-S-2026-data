#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5;
LL a[N];
LL n,m,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=5){
        if(m-(a[5]-a[4]+a[5]-a[3]+a[5]-a[2]+a[5]-a[1])>=0) cout<<5;
        else if(m-(a[4]-a[3]+a[4]-a[2]+a[4]-a[1])>=0) cout<<4;
        else if(m-(a[3]-a[2]+a[3]-a[1])>=0) cout<<3;
        else if(m-(a[2]-a[1])>=0) cout<<2;
    }
    for(int i=n;i>=1;i--){
        int num=1;
        if(m-(a[n]-a[i]*num)>=0){
            m-=(a[n]-a[i]*num);
            ans+=1;
            num+=1;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
