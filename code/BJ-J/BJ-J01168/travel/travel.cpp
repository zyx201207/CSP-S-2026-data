#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string p1,p2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2;
    cin>>p1>>p2;
    if(s1==p1){
        cout<<"1";
        if(s2[0]==p2[0] && s2[1]==p2[1]){
            cout<<"1";
            char s=s2[2],p=p2[2];
            if ((s=='C' && p=='D') || (s=='D' && p=='C')){
                cout<<"00";
            }
            else{
                cout<<"1";
                if ((s==p+1) || (p==s+1)){
                    cout<<"1";
                }
                else cout<<"0";
            }
        }
        else cout<<"000";
    }
    else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
