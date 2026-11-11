#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50;
string c1,c2,s1,s2,k1,k2;

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        char s12=s1[2],s22=s2[2];
        char s11=s1[0]+s1[1],s21=s2[0]+s2[1];
        if(s11==s21){
            cout<<1;
            if((s12<='C'&&s12>='A'&&s11>='A'&&s11<='C')||(s11=='D'&&s12=='F'||s11=='F'&&s12=='D')){
                cout<<1;
                if((s12==char(s22+1)&&s12!='D')||(char(s12+1)==s22&&s22!='D')){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
