#include<bits/stdc++.h>
using namespace std;
int a[200005],n;
int maxn=0;
void yu(int ceng,int shu,int id){
    if(ceng==0){
        maxn=max(maxn,shu);
        //cout<<shu<<' ';
        return;
    }
    for(int i=id+1;i<=n;i++){
        //cout<<'('<<id<<' '<<ceng<<')';
        yu(ceng-1,shu&a[i],i);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            //cout<<'*'<<i<<'*';
        yu(m-1,a[i],i);
    }
    cout<<maxn;
    return 0;
}
