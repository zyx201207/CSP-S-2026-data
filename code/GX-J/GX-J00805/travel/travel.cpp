#include <bits/stdc++.h>
using namespace std;
long long a1,b1;
string a2,b2;
bool cheak(char a){
    if(('A'<=a)&&(a<='C')) return 1;
    return 0;
}
bool nt(char a,char b){
    if(a=='A'&&b=='C') return false;
    return true;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){//02 01C 02 01D
        cout<<1;
        int c1=(a2[0]+'0')*10+(a2[1]+'0');
        int c2=(b2[0]+'0')*10+(b2[1]+'0');
        if(c1==c2){
            cout<<1;
            char d1=a2[2],d2=b2[2];
            if(cheak(d1)==cheak(d2)){
                cout<<1;
                if(nt(d1,d2)&&nt(d2,d1)){
                    cout<<1;
                }else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
