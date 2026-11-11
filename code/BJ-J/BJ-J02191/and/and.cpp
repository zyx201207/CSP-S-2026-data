#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int a[maxn];
signed main(){

    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);

    int n,m;
    bool specialPoint6=true;
    bool specialPoint7=true;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i-1) specialPoint6=false;
        if(a[i]>4) specialPoint7=false;
    }
    if(n<=20&&m<=n){
        //special point 1(5)

        //return 0;
    }
    if(m==1){
        //special point 2(1)
        int mx=-1;
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i]);
        }
        cout<<mx;
        return 0;
    }
    if(m==2){
        //special point 3(3)
        int mx=-1;
        for(int ft=1;ft<=n;ft++){
            for(int sc=1;sc<=n;sc++){
                mx=max(mx,(a[ft]&a[sc]));
            }
        }
        cout<<mx;
        return 0;
    }
    if(m==n){
        //special point 4(1)
        int ans=a[1];
        for(int i=1;i<=n;i++) ans&=a[i];
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        //special point 5(2)
        int mx=-1;
        for(int i=1;i<=n;i++){
            //without i
            int ans=0;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(ans==0) ans=a[j];
                ans&=a[j];
            }
            mx=max(mx,ans);
        }
        cout<<mx;
        return 0;
    }
    if(specialPoint6){
        //special point 6(2)
        int ans=0;
        int now=n;
        int step=0;
        while((now-1)!=0){
            if(ans==0) ans=now-1;
            ans&=(now-1);
            if(++step==m) break;
            now/=2;
        }
        cout<<ans;
        return 0;
    }
    if(specialPoint7){
        //special point 7(2)

    }
    //special point 8(1) or other()


    return 0;
}
