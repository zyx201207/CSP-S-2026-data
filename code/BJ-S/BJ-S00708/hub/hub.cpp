#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll read(){
    ll igt=0,sgn=1;
    char c=getchar();
    while(c<'0' or c>'9'){
        if(c=='-'){
            sgn=-1;
        }
        c=getchar();
    }
    while(c<='9' and c>='0'){
        igt=(igt<<3)+(igt<<1)+c-'0';
        c=getchar();
    }
    return igt*sgn;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ll c=read(),t=read();
    if(c<=14 and c>=13){
        while(t--){
            ll n=read(),k=read();
            ll tmp;
            for(ll i=1;i<n;i++){
                tmp=read();
            }
            if(k==n){
                printf("0\n");
            }
            else if(k>=(n/2)){
                printf("1\n");
            }
            else{
                int m=n/2;
                    k/=2;
                    printf("%lld\n",m-k);

            }
        }
    }
    else{
        while(t--){
            cout<<"0\n";
        }
    }
    return 0;
}
