#include <bits/stdc++.h>
using namespace std;
//t1
char c1[2],s1[3],c2[2],s2[3];
int f1=0,f2=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<'1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<'1';
            if(s1[2]>='A'&&s1[2]<='C')f1=0;
            else f1=1;
            if(s2[2]>='A'&&s2[2]<='C')f2=0;
            else f2=1;
            if(f1==f2){
                cout<<'1';
                if(s1[2]+(char)1==s2[2]||s1[2]-(char)1==s2[2])cout<<'1';
                else cout<<'0';
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}