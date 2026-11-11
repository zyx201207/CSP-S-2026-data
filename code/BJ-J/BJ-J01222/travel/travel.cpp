#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main() {
    freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;if(s1[2]=='F')s1[2]='E';if(s2[2]=='F')s2[2]='E';
    if(c1!=c2) cout<<"0000";
    else {
        cout<<1;
        if(stoi(s1)!=stoi(s2))cout<<"000";
        else {
            cout<<1;
            if(max(s1[2],s2[2])>'C'&&min(s1[2],s2[2])<'D')cout<<"00";
            else cout<<1<<(abs(s1[2]-s2[2])==1);
        }
    }
    return 0;
}
