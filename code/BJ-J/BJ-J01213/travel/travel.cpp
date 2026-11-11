#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        int k1=(s1[0]-'0')*10+(s1[1]-'0');
        int k2=(s2[0]-'0')*10+(s2[1]-'0');
        if(k1==k2){
            cout<<1;
            if(((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')) || ((s1[2]=='F' || s1[2]=='D') && (s2[2]=='F' || s2[2]=='D'))){
                cout<<1;
                if(max(s1[2],s2[2])<'D' && max(s1[2],s2[2])-min(s1[2],s2[2])==1){
                    cout<<1;
                }else if(min(s1[2],s2[2])>'D'){
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
}
//8:48 AC
