#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a,b;
    a=(s1[0]-'0')*10+(s1[1]-'0');
    b=(s2[0]-'0')*10+(s2[1]-'0');
    if(c1==c2){
        cout<<1;
        if(a!=b) cout<<"000";
        else{
            cout<<1;
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
                cout<<1;
                if((s1[2]=='C'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='C')){
                    cout<<"0";
                }
                else cout<<1;
            }
            else cout<<"00";
        }
    }
    else cout<<"0000";
    return 0;
}
