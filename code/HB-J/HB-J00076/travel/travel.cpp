#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int a, b, c, d;
char x, y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    a=a+(c1[1]-'0')+(c1[0]-'0')*10;
    b=b+(s1[1]-'0')+(s1[0]-'0')*10;
    c=c+(c2[1]-'0')+(c2[0]-'0')*10;
    d=d+(s2[1]-'0')+(s2[0]-'0')*10;
    x=s1[2], y=s2[2];
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<'1';
        if(b!=d){
            cout<<"000";
            return 0;
        }
        else{
            cout<<'1';
            if((x=='A' || x=='B' || x=='C') && (y=='D' || y=='F')){
                cout<<"00";
                return 0;
            }
            else{
                cout<<'1';
                if(x=='D' && y=='F'){
                    cout<<'1';
                    return 0;
                }
                else if(abs(x-y)==1){
                    cout<<'1';
                    return 0;
                }
                else cout<<'0';
            }
        }
    }
    return 0;
}
