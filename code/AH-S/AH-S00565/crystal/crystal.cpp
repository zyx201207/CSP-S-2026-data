#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m;
long long o[500009];
long long a[500009];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int op=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m<=10e8){
        sort(a+1,a+n+1);
    o[1]=0;
    long long k=2147483647;
    for(long long i=2;i<=n-1;i++){
        o[i]=o[i-1]+(a[i]-a[i-1])*(i-1);
    }
    bool www=0;
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(o[j]-o[i]>m){
                continue;

            }
            if(o[j]-o[i]==m){
                cout<<j-i+1;
                return 0;
            }
        }
    }
    }
    else{
        for(int i=5000;i<=n;i++){
            if(a[i]=i){
                op=1;
            }
        }
        int lll=0;
        if(op==1){
            for(int i=1;i<=m;i++){
                if(i*i+i<=2*m){
                    lll=max(i,lll);
                }
                else break;
            }
            cout<<lll;
            return 0;
        }
        else{
                int sum=0;
                int ooo=0;
            int hhh=a[3]-a[2];
            int hh=m/hhh;
            for(int i=1;;i++){
                if(sum<=m){
                    ooo=max(ooo,sum);
                }
                else break;
                sum+=i;
            }
            cout<<ooo;
            return 0;
        }
    }
    return 0;
}
