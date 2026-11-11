#include<bits/stdc++.h>
using namespace std;
string c1,s1;
string c2,s2;


int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
            cout<<"1";

            if(s1[0]==s2[0]&&s1[1]==s2[1]){
                cout<<"1";
                int q=0,w=0;
                if(s1[2]<='C')q=0;
                else q=1;
                if(s2[2]<='C')w=0;
                else w=1;
                if(q==w){
                    cout<<"1";
                    int e=0+s1[2]-'A',r=0+s2[2]-'A';
                    if(abs(e-r)==1)cout<<"1";
                    else if(w==1)cout<<"1";
                    else cout<<"0";
                }
                else cout<<"00";
            }
            else cout<<"000";
    }
    else cout<<"0000";


    return 0;
}
