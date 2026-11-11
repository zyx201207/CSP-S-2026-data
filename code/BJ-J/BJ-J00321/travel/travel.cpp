#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int a1,a2,b1,b2;
    char a,b;
    cin>>a1>>a2>>a>>b1>>b2>>b;
    if(a1==b1){
            cout<<1;
        if(a2==b2){
            cout<<1;
        }
        else{
            cout<<0;
        }
        if((a>='D'&&b>='D')||(a<='C'&&b<='C')&&a2==b2){
                cout<<1;
            }
            else cout<<0;
        if(a2==b2&&(a-b==1||b-a==1)&&((a>='D'&&b>='D')||(a<='C'&&b<='C'))){
            cout<<1;
        }
        else cout<<0;
    }
    else
    {
        cout<<0<<0<<0<<0;
    }
return 0;
}
