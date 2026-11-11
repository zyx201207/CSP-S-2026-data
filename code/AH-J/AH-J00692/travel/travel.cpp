#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,ci,si;
    cin>>c>>s>>ci>>si;
    if(c==ci){
        cout<<"1";
        if(s[1]==si[1]&&s[2]==si[2]){
            cout<<"1";
            if(s[3]==D&&si[3]!=F||s[3]!=D&&si[3]==F)
                cout<<"0";
            else{
                cout<<"1";
                if(s[2]==si[2]-1||s[2]-1==si[2]||s[3]-si[3]==1||si[3]-s[3]==1)
                    cout<<"1";
                else{
                    cout<<"0";
                }
            }
        }
        else{
            cout<<"00";
            if(s[2]==si[2]-1||s[2]-1==si[2]){
                cout<<"1";
            }
            else {
                cout<<"0";
            }
        }
    }
    else{
        cout<<"0000";
    }

    return 0;
}
