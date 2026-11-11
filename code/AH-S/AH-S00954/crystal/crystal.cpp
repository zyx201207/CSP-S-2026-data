#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long a[100005]={0};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long imax=0;
    long long nowmax=1;
    long long had=m;
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            if(a[j]<a[i] and had>=a[i]-a[j] or a[j]==a[i] and i!=j){
                had-=(a[i]-a[j]);
                nowmax++;
            }else{
                if(nowmax>imax){
                    imax=nowmax;
                }else{
                    nowmax=1;
                    had=m;
                }
            }
        }
    }
    cout<<imax;
    return 0;
}
