#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct asd{
    long long q;
    char w;
}a[200009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].q>>a[i].w;
    }
    long long l=1,r=n;
    long long ql=a[1].q;
    long long qr=a[n].q;
    char wl=a[1].w;
    char wr=a[n].w;
    while(l<r){
        if(wl==wr){
            if(ql<qr){
                qr-=ql;
                l+=1;
                ql=a[l].q;
                wl=a[l].w;
            }else if(ql>qr){
                ql-=qr;
                r-=1;
                qr=a[r].q;
                wr=a[r].w;
            }else{
                l+=1;
                r-=1;
                ql=a[l].q;
                wl=a[l].w;
                qr=a[r].q;
                wr=a[r].w;
            }
        }else{
            if(ql<qr){
                qr-=ql;
                ans+=ql;
                l+=1;
                ql=a[l].q;
                wl=a[l].w;
            }else if(ql>qr){
                ql-=qr;
                ans+=qr;
                r-=1;
                qr=a[r].q;
                wr=a[r].w;
            }else{
                ans+=qr;
                l+=1;
                r-=1;
                ql=a[l].q;
                wl=a[l].w;
                qr=a[r].q;
                wr=a[r].w;
            }
        }
    }
    cout<<ans;
    return 0;
}
