#include <bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3)  cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(c1==c3&&(c2[0]==c4[0]&&c2[1]==c4[1]))  cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if(c1==c3&&(c2[0]==c4[0]&&c2[1]==c4[1])&&(c2[2]-c4[2]<=5||c4[2]-c2[2]<=5)){
        if(c2[2]=='D'||c2[2]=='F'){
            if(c4[2]=='F'||c4[2]=='D'){
                cout<<"11";
                return 0;
            }
        }
        else if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
            if(c4[2]=='F'||c4[2]=='D'){
                cout<<"00";
                return 0;
            }
            if(c2[2]+1==c4[2]||c2[2]-1==c4[2]){
                cout<<"1";
                return 0;
            }
            cout<<"0";
        }
    }
    return 0;
}
