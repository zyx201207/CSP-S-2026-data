#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)cout<<"0000";
    else{
        cout<<1;
        if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"000";
        else{
            cout<<1;
            if((s1[2]<='C'&&s2[2]>'C')||(s1[2]>'c'&&s2[2]<='c'))cout<<"00";
            else{
                cout<<1;
                if(abs(int(s1[2])-int(s2[2]))==1)cout<<1;
                else cout<<0;
            }
        }
    }
    return 0;
}
