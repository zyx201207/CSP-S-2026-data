#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        if(m==1)
            n=1;
    }for(int i=0;i<=n;i++){
        if(m==2)
            n=2;
    }for(int i=0;i<=n;i++){
         if(m==1)
            i--;
            cout<<1;
    }for(int i=0;i<=n;i++){
        if(m==3)
            cout<<3;
    }return 0;
}
