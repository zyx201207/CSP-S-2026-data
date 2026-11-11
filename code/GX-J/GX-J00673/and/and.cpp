#include <bits/stdc++.h>
using namespace std;
bool bi(int x,int z[],int c[]){
    for(int i=0;i<x;i++){
        c[i]=z[0];
        for(int j=0;j<1005;j++){
            if(z[j]>c[i]){
                c[i]=z[j];
            }
        }
    }
    return c;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[1005];
    int a1[1005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m-1;i++){
        if(i==0){
            b= bi(m,a,a1)[i] and bi(m,a,a1)[i+1];
        }
        else{
            b=b and bi(m,a,a1)[i+1];
        }

    }
    cout<<b;
}
