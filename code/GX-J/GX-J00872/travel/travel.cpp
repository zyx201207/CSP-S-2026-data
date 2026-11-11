#include<bits/stdc++.h>
using namespace std;
struct p{
    int c;
    string m;
    int h=m[0]+m[1];
    char r=m[2];
}a[12];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++){
        cin>>a[i].c>>a[i].m;

    }
    for(int i=1;i<=1;i++){
        if(a[i].c==a[i+1].c){
            cout<<1;
        }
        else{
            cout<<0;
        }
        if(a[i].h==a[i+1].h){
            cout<<1;
        }
        else{
            cout<<0;
        }

    }
    return 0;
}
