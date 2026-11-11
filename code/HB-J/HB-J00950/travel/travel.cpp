#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c1>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<1;
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            cout<<1;
            if(char(s1[2])<='C'&&char(s2[2])<='C'){
                cout<<1;
                if(char(s1[2]+1)==char(s2[2])||char(s1[2]-1)==char(s2[2]))
                    cout<<1;
                else
                    cout<<0;
            }
            else if(char(s1[2]+s2[2])>'H' && char(s1[2]+s2[2])<='I'){
                cout<<1;
                if(char(s1[2]+1)==char(s2[2])||char(s1[2]-1)==char(s2[2]))
                    cout<<1;
                else
                    cout<<0;
            }
            else
                cout<<0;
        }
        else
            cout<<0;
    }else
        cout<<0;
    return 0;
}
