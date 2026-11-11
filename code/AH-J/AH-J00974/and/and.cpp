#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200005],sum=0,f=1,aa=0,bb=0,cc=0;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i==1){
            sum=a[i];
        }else{
            sum=sum&a[i];
        }
        if(a[i]>4){
            f=0;
        }
        if(a[i]==1){
            aa=1;
        }else if(a[i]==2){
            bb=1;
        }else if(a[i]==3){
            cc=1;
        }
    }
    sort(a+1,a+1+n);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(m==n){
        cout<<sum;
        return 0;
    }
    if(m==2){
        long long mx=0;
        for(int i=n;i>=3;i--){
            for(int j=i-1;j>=2;j--){
                mx=max(mx,a[i]&a[j]);
            }
        }
        cout<<mx;
        return 0;
    }
    if(f==1){
         cout<<0;
    }
        long long mx=INT_MIN;
        sum=a[n];
        for(int i=n-1;i>=n-m+1;i--){
            sum&=a[i];
        }
        cout<<sum;
    return 0;
}
