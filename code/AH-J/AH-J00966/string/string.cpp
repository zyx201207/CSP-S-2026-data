#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
struct lol{
    ll sum;
    char h;
};
lol k[200005];
lol a[200005];
lol b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    ll num=0;
    for(ll i=1;i<=n;i++){
        cin>>k[i].sum>>k[i].h;
        num+=k[i].sum;
    }
    num=num/2;
    ll sum1=0;
    ll sia,sib;
    for(ll i=1;;i++){
        if(k[i].sum+sum1<=num){
            sum1+=k[i].sum;
            a[i].sum=k[i].sum;
            a[i].h=k[i].h;
        }else{
            a[i].sum=num-sum1;
            a[i].h=k[i].h;
            sia=i;
            break;
        }
    }
    sum1=0;
    for(ll i=n;;i--){
        if(k[i].sum+sum1<=num){
            sum1+=k[i].sum;
            b[n-i+1].sum=k[i].sum;
            b[n-i+1].h=k[i].h;
        }else{
            b[n-i+1].sum=num-sum1;
            b[n-i+1].h=k[i].h;
            sib=n-i+1;
            break;
        }
    }

    ll ina=1,inb=1;
    ll ci=0;
    while(ina<=sia&&inb<=sib){
        if(a[ina].h==b[inb].h){
            if(a[ina].sum!=b[inb].sum){
                if(a[ina].sum<b[inb].sum){
                    b[inb].sum-=a[ina].sum;
                    ina++;
                }else{
                    a[ina].sum-=b[inb].sum;
                    inb++;
                }
            }else{
                ina++;
                inb++;
            }
        }else{
            if(a[ina].sum!=b[inb].sum){
                if(a[ina].sum<b[inb].sum){
                    b[inb].sum-=a[ina].sum;
                    ci+=a[ina].sum;
                    ina++;
                }else{
                    a[ina].sum-=b[inb].sum;
                    ci+=b[inb].sum;
                    inb++;
                }
            }else{
                ci+=a[ina].sum;
                ina++;
                inb++;
            }
        }
    }
    cout<<ci;
    return 0;
}
