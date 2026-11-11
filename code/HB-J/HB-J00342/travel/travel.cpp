#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)cout<<"0000";
    else{
        cout<<1;
        if(s1[0]*10+s1[1]!=s2[0]*10+s2[1])cout<<"000";
        else{
            cout<<1;
            int a=s1[2]-'A',b=s2[2]-'A';
            if(a<3&&b>=3||a>=3&&b<3)cout<<"00";
            else{
                cout<<1;
                if(a-b==1||b-a==1)cout<<1;
                else cout<<0;
            }
        }
    }
    return 0;
}
