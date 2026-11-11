#include <bits/stdc++.h>
using namespace std;
struct aj{
    long long x;
    char y;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long m,l;
    aj a[n+1];
    m=n/2;
    for(int i=1;i<=n;++i){
        cin>>a[i].x>>a[i].y;
    }
    if(n%2==1){
        l=n/2+1;
    }else{
        l=n/2;
    }
    if(n<=2){
        if(a[1].y==a[2].y){
            cout<<"0";
            return 0;
        }else{
            if(a[1].x>=a[2].x){
                cout<<a[2].x;
                return 0;
            }else{
                cout<<a[1].x;
                return 0;
            }
        }
    }
    for(int i=n;i>=l;--i){
        if(a[i].y==a[i-1].y){
            a[i-1].x+=a[i].x;
            a[i].x=0;
        }
    }
     for(int i=1;i<=l-1;++i){
        if(a[i].y==a[i+1].y){
            a[i+1].x+=a[i].x;
            a[i].x=0;
        }
    }
    long long sum=0,sa;
      for(int i=1;i<=m;i++){
            if(a[i].x>=a[n-i+1].x){
                sa=a[i].x;
            }else{
                sa=a[n-i+1].x;
            }
        if(a[i].y==a[n-i+1].y){
            if(a[i].x==a[n-i+1].x){
                    sum+=0;
            }else{
                sum=sum+abs(a[i].x-a[n-i+1].x);
            }
        }else{
            sum+=sa;
        }
    }
    cout<<sum;
    return 0;
}
