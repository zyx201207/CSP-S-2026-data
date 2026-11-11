#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    cin>>s1>>s2>>c1>>c2;
    if(s1==c1){
        cout<<1;
        if(s2[1]==c2[1]){
            cout<<1;
            if((s2[2]=='A'&&(c2[2]=='B'||c2[2]=='C'))||(s2[2]=='B'&&(c2[2]=='A'||c2[2]=='C'))||
            (s2[2]=='C'&&(c2[2]=='B'||c2[2]=='A'))){
                cout<<1;
                if(s2[2]=='A'&&c2[2]=='B'||s2[2]=='B'&&(c2[2]=='A'||c2[2]=='C')||
                s2[2]=='C'&&s2[2]=='B'||s2[2]=='D'&&c2[2]=='F'||s2[2]=='F'&&c2[2]=='D'){
                    cout<<1;

                }
                else cout<<0;
            }
            else cout<<"00";
        }
        else{
            cout<<"000";
        }
    }
    else cout<<"0000";
    return 0;
}
