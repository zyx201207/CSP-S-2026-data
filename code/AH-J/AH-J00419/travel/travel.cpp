#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int sa=10*(s1[0]-'0')+(s1[1]-'0');
    int sb=10*(s2[0]-'0')+(s2[1]-'0');
    char sp=s1[2],sq=s2[2];
    if(c1==c2){
        if(sa==sb){
            if(((sp>='A'&&sp<='C')&&(sq>='A'&&sq<='C'))||((sp=='D'||sq=='F')&&(sq=='D'||sq=='F'))){
                if((sp=='A'&&sq=='B')||(sq=='A'&&sp=='B')||(sp=='B'&&sq=='C')||(sq=='B'&&sp=='C')||(sp=='D'&&sq=='F')||(sq=='D'&&sp=='F')){
                    cout<<"1111";
                    return 0;
                }
                cout<<"1110";
                return 0;
            }
            cout<<"1100";
            return 0;
        }
        cout<<"1000";
        return 0;
    }
    cout<<"0000";
    return 0;
}
