#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    ll S1=0,S2=0;
    char A,B;
    S1=s1[0]*10+s1[1];
    A=s1[2];
    S2=s2[0]*10+s2[1];
    B=s2[2];
    if(c1==c2){
        cout<<1;
        if(S1==S2){
            cout<<1;
            if(A<='C'&&B<='C'||A>'C'&&B>'C'){
                cout<<1;
                if((int)(abs(A-B))==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
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
