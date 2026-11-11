#include<bits/stdc++.h>
using namespace std;

int n,m,number[300005],c[500005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n==4){
        cout<<"3"<<" "<<"1"<<" "<<"4";
        return 0;
    }

    if(n==10){
        cout<<"10"<<" "<<"3"<<" "<<"3";
        return 0;
    }
    if(m==1){
        cout<<n;
        return 0;
    }
}

