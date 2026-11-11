#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.in","r",stdin);
    int c,t,n,d,x,u,v,z=0,xj,xi;
    cin>>c>>t;
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            if(xi-xj<=d){
                z++;
            }
        }
    }
    cout<<z;
    return 0;
}
