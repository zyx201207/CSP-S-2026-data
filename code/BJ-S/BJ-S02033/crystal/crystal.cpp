#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+10;
int n,m;
int a[N];
int ans=0;

void solve1(){
    for(int k=1;k<=n;k++){
        int b[N]={};
        b[1]=0;
        for(int i=k+1;i<=n;i++){
            b[i]=a[i]-a[i-1];
        }
        int c[N];
        c[1]=b[1];
        for(int i=k+1;i<=n;i++){
            c[i]=b[i]*(i-1);
        }
        b[1]=c[1];
        for(int i=k+1;i<=n;i++){
            b[i]=b[i-1]+c[i];
        }
        int cnt;
        for(int i=k;i<=n;i++){
            if(b[i]<=m){
                cnt=i-k+1;
            }else{
                break;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
}

void solve2(){
    int b[N]={};
    b[1]=0;
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    a[1]=b[1];
    for(int i=2;i<=n;i++){
        a[i]=b[i]*(i-1);
    }
    b[1]=a[1];
    for(int i=2;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        if(b[i]<=m){
            ans=i;
        }else{
            break;
        }
    }
    cout<<ans;
}

void solve3(){
    int b[N]={};
    b[1]=0;
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    a[1]=b[1];
    for(int i=2;i<=n;i++){
        a[i]=b[i]*(i-1);
    }
    b[1]=a[1];
    for(int i=2;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        if(b[i]<=m){
            ans=i;
        }else{
            break;
        }
    }
    cout<<ans;
}

signed main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flag1=true;
    bool flag2=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            flag1=false;
        }
        if(i>2&&abs(a[i]-a[i-1])!=abs(a[i-1]-a[i-2])){
            flag2=false;
        }
    }
    sort(a+1,a+n+1);
    if(flag1==true||flag2==true){
        solve3();
    }else if(n<=3000){
        solve1();
    }else{
        solve2();
    }

    return 0;
}
