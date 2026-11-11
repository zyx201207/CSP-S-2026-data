#include <bits/stdc++.h>
using namespace std;
const int N=1e5+9;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    c1=' '+c1,c2=' '+c2,s1=' '+s1,s2=' '+s2;
    if(c1==c2){
        cout<<"1";
        if(s1[1]==s2[1]&&s1[2]==s2[2]){
            cout<<"1";
            if(s1[3]>='A'&&s1[3]<='C'&&s2[3]>='D'&&s2[3]<='F')cout<<"00";
            else{
                cout<<"1";
                if(s1[3]>=s2[3])swap(s1,s2);
                if((s1[3]=='A'&&s2[3]=='B')||(s1[3]=='B'&&s2[3]=='C')||(s1[3]=='D'&&s2[3]=='F'))cout<<"1";
                else cout<<"0";
            }   
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}