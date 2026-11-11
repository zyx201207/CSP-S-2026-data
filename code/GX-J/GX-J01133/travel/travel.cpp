#include <bits/stdc++.h>
using namespace std;
int c1;
int c2;
string s1;
string s2;
int main()
{
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0]){
            cout<<"1";
            if(s1[1]!=s2[1]&&s1=="C"&&s2=="C"&&s1=="D"&&s2=="D"){
               cout<<"1";
            }
        }

    }

    return 0;
}
