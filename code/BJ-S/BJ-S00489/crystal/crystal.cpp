#include<bits/stdc++.h>
using namespace std;
long long n[500009]={};
long long sum[500009]={};
int main(){
    int a;
    long long b;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>a>>b;
    long long cnt=0;
    for(int i=1;i<=a;i++){
        cin>>n[i];
    }
    sort(n+1,n+a+1);
    for(int i=1;i<=a;i++){
        cnt+=n[i];
        sum[i]=cnt;
    }
    int out=1;
    for(int i=1;i<a;i++){
        if(((n[i+1]*i)-sum[i])<=b){
            out=i+1;
        }
    }
    cout<<out;
    return 0;
}
