#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[3],s2[3];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1;
    for(int i=0;i<3;i++) cin>>s1[0];
    cin>>c2;
    for(int i=0;i<3;i++) cin>>s2[0];
    if(c1==c2){
        cout<<'1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<'1';
            if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
                cout<<'1';
                if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1) cout<<'0';
                else cout<<'0';
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
