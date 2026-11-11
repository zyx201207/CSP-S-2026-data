#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    cin>>n;
    int a1,a2;
    cin>>a1;
    char a,b;
    cin>>a>>m>>a2>>b;
    if(a<b)swap(a,b);
    if(n!=m){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(a1!=a2){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(!((a<='c'&&b<='c')||(a>='d'&&b>='d'))){
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(a-b==1)cout<<1;
    else      cout<<0;
}
