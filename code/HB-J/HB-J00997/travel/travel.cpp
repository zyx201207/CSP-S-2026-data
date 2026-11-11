#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string a,b;
    cin>>c1>>a>>c2>>b;
    if(c1!=c2){
        cout<<"0000\n";
        return 0;
    }
    else{
        cout<<1;
        if((int)(a[0]-'0')+(int)(a[1]-'0')==(int)(b[0]-'0')+(int)(b[1]-'0')){
            cout<<1;
        }
        else{
            cout<<"000";
            return 0;
        }
        if(((int)(a[2]-'A')<3&&(int)(b[2]-'A')<3)||((int)(a[2]-'A')>=3&&(int)(b[2]-'A')>=3)){
            cout<<1;
        }
        else{
            cout<<"00";
            return 0;
        }
        if((a[2]=='A'&&b[2]=='B')||(a[2]=='B'&&(b[2]=='A'||b[2]=='C'))||(a[2]=='C'&&b[2]=='B')||(a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D')){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    return 0;
}
