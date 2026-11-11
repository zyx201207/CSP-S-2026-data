#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long t,a[200005][2],now=1;
    long long ans=0;
    cin>>t;
    a[0][0]=a[0][1]=0;
    for (int i=1;i<=t;i++){
        char c;
        cin>>a[now][0]>>c;
        ans+=a[now][0];
        a[now][1]=c-'a'+1;
        if (a[now][1]==a[now-1][1]){
            a[now-1][0]+=a[now][0];
            now--;
        }
        now++;
    }
    long long l=0,r=ans,lw=1,rw=now,Ot=0;
    long long lr=0,las=0;
    while (lw<rw){
        long long bg=min(a[lw][0],a[rw][0]);
        if (lr==1){
            bg=min(a[lw][0],las);
        }else if (lr==2){
            bg=min(a[rw][0],las);
        }
        las=max(a[lw][0],a[rw][0])-bg;
        if (a[lw][1]!=a[rw][1]){
            Ot+=bg;
        }
        l+=bg;
        r-=bg;
        if (a[lw][0]>a[rw][0]){
            rw--;
            lr=2;
        }else if (a[lw][0]<a[rw][0]){
            lw++;
            lr=1;
        }else{
            lw++;
            rw--;
            lr=0;
        }
    }
    cout<<min(ans-Ot,Ot);
    return 0;
}

