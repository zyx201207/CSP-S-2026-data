#include<bits/stdc++.h>
using namespace std;
int a[700001],b[700001]={},c[700001],d[700001]={};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool isa=true,isb=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1&&a[i]<a[i-1]) isa=false;
        if(i!=1&&a[i]==a[i-1]) isb=false;
    }
    if(isa==true){
        for(int i=1;i<=n;i++){
            b[a[i]]++;
        }
        int x=0;
        for(int i=1;i<=700000;i++){
            if(b[i]!=0){
                x++;
                c[x]=b[i];
            }
        }
        for(int i=1;i<=x;i++){
            cout<<i<<" ";
        }
    }
    if(isb==true){
        for(int i=1;i<=m;i++){
            cout<<i<<" ";
        }
    }
    return 0;
}

