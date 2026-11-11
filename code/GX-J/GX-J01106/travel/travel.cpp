#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string pd="0000";
    if(c1==c2){
        pd[0]='1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            pd[1]='1';
            if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
                pd[2]='1';
                if(max(s1[2],s2[2])-min(s1[2],s2[2])==1){
                    pd[3]='1';
                }
                else{
                    cout<<pd;
                    return 0;
                }
            }
            else{
                cout<<pd;
                return 0;
            }
        }
        else{
            cout<<pd;
            return 0;
        }
    }
    else{
        cout<<pd;
        return 0;
    }
    cout<<pd;
    return 0;
}
