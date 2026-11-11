#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(!(c1[0]==c2[0]&&c1[1]==c2[1])){
        cout<<"0000";
        return 0;
    }

    if(!(s1[0]==s2[0]&&s1[1]==s2[1])){
        cout<<"1000";
        return 0;
    }
    char a=s1[2],b=s2[2];
    if(!((a<=67&&b<=67)||(a>67&&b>67))){
        cout<<"1100";
        return 0;
    }
    if(!((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='D'&&b=='F')||(a=='F'&&b=='D'))){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
