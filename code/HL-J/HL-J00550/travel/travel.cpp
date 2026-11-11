#include<bits/stdc++.h>
using namespace std;
int c1,c2;
struct s{
    int a;
    char b;
};
s s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1.a>>s1.b>>c2>>s2.a>>s2.b;
    if(c1==c2){
        cout<<1;
        if(s1.a==s2.a){
            cout<<1;
            if((int(s1.b)<=67)&&(int(s2.b)<=67)||(int(s1.b)>=68)&&(int(s2.b)>=68)){
                cout<<1;
                if(int(s1.b)==int(s2.b)+1||int(s1.b)==int(s2.b)-1){
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";


    return 0;
}
