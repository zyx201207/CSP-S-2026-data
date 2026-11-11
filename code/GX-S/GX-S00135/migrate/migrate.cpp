#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6;

int c,t,n,ans;

ll read(){
    ll x=0,f=1;
    char c;
    c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return f*x;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();t=read();
    if(c==11||c==12){
        while(t--){
            ll n,d,x1,x2,x;
            n=read();d=read();
            for(int i=1;i<=n;i++){
                if(i==1) x1=read();
                else if(i==2) x2=read();
                else read();
            }
            x=x2-x1;
            if(d/x>=2) cout<<max((ll)0,n-2*(d/x)+1)<<"\n";
            else cout<<0<<"\n";
        }
    }
    else{
        while(t--) cout<<0<<"\n";
    }
    return 0;
}
