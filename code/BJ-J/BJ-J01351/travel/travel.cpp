#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long c1,c2,pai1,pai2,lie1,lie2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    pai1=(s1[0]-'0')*10+(s1[1]-'0');
    pai2=(s2[0]-'0')*10+(s2[1]-'0');
    if(c1==c2){
        cout<<1;
        if(pai1==pai2){
            cout<<1;
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
                cout<<1;
                if((abs(s1[2]-s2[2])==1)||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
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
