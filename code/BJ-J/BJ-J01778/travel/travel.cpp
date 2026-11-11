#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
char c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    if(a1==a2){
        cout<<1;
        if(b1==b2){
            cout<<1;
            if((c1<='c'&&c2<='c')||(c1>'c'&&c2>'c')){
                cout<<1;
                if(abs(c1-c2)==1||c1+c2=='D'+'F') cout<<1;
                else cout<<0;
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
