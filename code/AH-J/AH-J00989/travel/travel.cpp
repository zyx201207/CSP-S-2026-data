#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2){
        cout<<"1";
        if (c1[0]+c1[1]==c2[0]+c2[1]){
            cout<<"1";
            if ((c1[2]=="A"||c1[2]=="B"||c1[2]=="C")&&(c2[2]=="A"||c2[2]=="B"||c2[2]=="C")
            ||(c1[2]=="D"||c1[2]=="F")&&(c2[2]=="D"||c2[2]=="F")) cout<<"1";
            else cout<<"0";
            if ((c1[2]=="A"||c1[2]=="C")&&c2[2]=="B"
            ||c1[2]=="B"&&(c2[2]=="A"||c2[2]=="C")) cout<<"1";
            else cout<<"0";
        }
        else cout<<"0";
    }
    else cout<<"0000";
}
