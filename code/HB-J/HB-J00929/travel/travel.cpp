#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    char a,b;
    a=s1[2];
    b=s2[2];
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            if(a>='D'&&b>='D'){
                cout<<"11";
            }
            else if(a<'D'&&b<'D'){
                cout<<"1";
                if(abs(int(a)-int(b))==1) cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
