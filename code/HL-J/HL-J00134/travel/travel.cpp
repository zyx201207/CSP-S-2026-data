#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a,c;
char e,f;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    e=s1[2];
    f=s2[2];
    a=c1;
    c=c2;
    if(a==c){
        cout<<"1";
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            cout<<"1";
            if((e>=68 && e<=69 && f>=68 && f<=69) || (e>=65 && e<=67 && f>=65 && f<=67)){
                cout<<"1";
                int t=int(e)+int(f);
                if(t%2==1){
                    cout<<"1";
                }else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
