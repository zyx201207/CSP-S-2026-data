#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ci,cii,si,sii;
    cin>>ci>>si>>cii>>sii;
    if(ci==cii){
        cout<<"1";
        if(si[0]==sii[0]&&si[1]==sii[1]){
            cout<<"1";
            if(((si[2]=='D'||si[2]=='F') && (sii[2]=='D'||sii[2]=='F')) || ((si[2]=='A'||si[2]=='B'||si[2]=='C') && (sii[2]=='A'||sii[2]=='B'||sii[2]=='C'))){
                cout<<"1";
                if(((si[2]=='D'||si[2]=='F') && (sii[2]=='D'||sii[2]=='F')) || ((si[2]=='A'||si[2]=='B') && (sii[2]=='A'||sii[2]=='B')) || ((si[2]=='C'||si[2]=='B') && (sii[2]=='C'||sii[2]=='B')) ){
                    cout<<"1";
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
