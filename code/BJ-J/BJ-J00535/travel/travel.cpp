#include <iostream>
#include <cstdio>
#include <cstring>//0 1 2 3 5
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1.compare(c2))cout<<"0000";
    else{
        cout<<1;
        if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"000";
        else{
            cout<<1;
            int a=s1[2]-'A',b=s2[2]-'A';
            if((a<3&&b>=3) && (a>=3&&b<3))cout<<"00";
            else if(a>=3 && b>=3)cout<<11;
            else {
                cout<<1;
                if(max(a,b)-min(a,b)==1)cout<<1;
                else cout<<0;
            }
        }
    }
    return 0;
}
