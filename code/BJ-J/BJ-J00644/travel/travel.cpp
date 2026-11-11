#include<bits/stdc++.h>
using namespace std;
int a1,a2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>s1>>a2>>s2;
    if(a1==a2){
        cout<<1;
        if(s1[0]==s2[0] and s1[1]==s2[1]){
            cout<<1;
            if(((s1[2]=='A' or s1[2]=='B' or s1[2]=='C')and(s2[2]=='A' or s2[2]=='B' or s2[2]=='C'))or((s1[2]=='D' or s1[2]=='F')and(s2[2]=='D' or s2[2]=='F'))){
                cout<<1;
                if(s1[2]==s2[2]+1 or s2[2]==s[1]+1){
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";


    return 0;
}
