#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int x1,x2;
int a1,a2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        x1=10*int(s1[0]-'0')+int(s1[1]-'0');
        x2=10*int(s2[0]-'0')+int(s2[1]-'0');
        if(x1==x2){
            cout<<"1";
            a1=int(s1[2]-'A');
            a2=int(s2[2]-'A');
            if((a1<=2 && a2<=2) || (a1>2 && a2>2)){
                cout<<"1";
                if(a1+1==a2 || a1-1==a2){
                    cout<<"1";
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
