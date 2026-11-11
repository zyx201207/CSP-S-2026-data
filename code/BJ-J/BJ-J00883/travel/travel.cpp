#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(s1[2]=='F') s1[2]='E';
    if(s2[2]=='F') s2[2]='E';
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
                cout<<1;
                if(abs(int(s1[2]-s2[2]))==1){
                    cout<<1<<"\n";
                }else{
                    cout<<"0\n";
                }
            }else{
                cout<<"00\n";
            }
        }else{
            cout<<"000\n";
        }
    }else{
        cout<<"0000"<<"\n";
    }

    return 0;
}
