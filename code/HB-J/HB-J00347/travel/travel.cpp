#include <bits/stdc++.h>
using namespace std;
int data[10]={0,0,0,1,1};
int len[10]={0,1,2,50,51};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2){
        cout<<1;
        if (s1[0]+s1[1]==s2[0]+s2[1]){
            cout<<1;
            if (data[s1[2]-'A']==data[s2[2]-'A']){
                cout<<1;
                if (abs(len[s1[2]-'A']-len[s2[2]-'A'])==1)
                    cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}

