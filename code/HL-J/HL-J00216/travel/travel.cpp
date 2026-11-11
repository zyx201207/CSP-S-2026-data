#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3) cout<<"1";
    else if(c1!=c3) cout<<"0";
    int s=0;
    for(int i=0;i<2;i++){
        if(c2[i]==c4[i]) s++;
        if(s==2) cout<<"1";
        else if(c2[i]!=c4[i]) cout<<"0";
    }
    for(int i=0;i<1;i++){
    if(c2[2]=='A' && c4[2]=='B' || c4[2]=='C') cout<<"1";
        else if(c2[2]=='B' && c4[2]=='A' || c4[2]=='C') cout<<"1";
        else if(c2[2]=='C' && c4[2]=='A' || c4[2]=='B') cout<<"1";
        else if(c2[2]=='D' && c4[2]=='F') cout<<"1";
        else if(c2[2]=='F' && c4[2]=='D') cout<<"1";
        else cout<<"0";
    }
    for(int i=0;i<1;i++){
        if(c2[2]=='A' && c4[2]=='B') cout<<"1";
        else if(c2[2]=='B' && c4[2]=='A' || c4[2]=='C') cout<<"1";
        else if(c2[2]=='C' && c4[2]=='B') cout<<"1";
        else if(c2[2]=='D' && c4[2]=='F') cout<<"1";
        else if(c2[2]=='F' && c4[2]=='D') cout<<"1";
        else cout<<"0";
    }



    return 0;
}
