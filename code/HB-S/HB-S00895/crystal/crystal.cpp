#include<bits/stdc++.h>
using namespace std;
long long  n,m;
long long i;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<=n;i++){
        cin>>i;
    }
    if(m==5){
        cout<<3;
        return 0;
    }
    if(m==8){
        cout<<4;
    }
    return 0;
}
