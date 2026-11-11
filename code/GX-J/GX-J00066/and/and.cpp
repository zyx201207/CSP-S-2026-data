#include<bits/stdc++.h>
using namespace std;
long long snm1=0;
long long f(long long a,long long s){
    if(a==0){
        return s;
    }
    s=a%2s*10;
    f(a/2);
}
long long f2(long long a,long long s){
    if(a==0){
        return s;
    }
    for(int i=1;i<=snm1;i++)
    s=a%2s*10*w;
    f(a/10);
}
long long f3(long b1,long b2,long long abc){
    b1=f(b1);
    b2=f(b2);
    while(b1!=0||b2!=0){
        if(b1%10==b2%10&&b1%10==1){
            abc=abc*10+1;
        }
        else{
            abc*=10;
        }
    }
    return abc=f2(abc);
}
int main(){
    freopen("and.in","r","std.in");
    freopen("and.out","w","std.out");
    int cnt[200005],s,n,a;
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>cnt[i];
    }
    return 0;
}
