#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int t1=(s1[0]-'0')*10+s1[1]-'0';
    int t2=(s2[0]-'0')*10+s2[1]-'0';
    if(c1==c2){
        cout<<"1";
        if(t1==t2){
            cout<<"1";
            if(!((s1[2]>'C')^(s2[2]>'C'))){
                cout<<"1";
                if(min(s1[2],s2[2])+1==max(s1[2],s2[2]))cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
