#include<bits/stdc++.h>
using namespace std;
int c1,c2,a1,a2;
char s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>a1>>s1>>c2>>a2>>s2;
    if(c1!=c2)cout<<"0000";
    else {
        cout<<"1";
        if(a1!=a2)cout<<"000";
        else{
            cout<<"1";
            if(s2<'D'&&s1>'C'||s1<'D'&&s2>'C')cout<<"00";
                else {
                cout<<"1";
                if(s2==1+s1||s1==1+s2)cout<<"1";
                else cout<<"0";
            }
        }
    }
    return 0;
}
