#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,d;
    int e,f;
    string s1,s2;
    cin>>a>>s1>>b>>s2;
    c=(s1[0]-'0')*10+s1[1]-'0';
    d=(s2[0]-'0')*10+s2[1]-'0';
    e=s1[2]-'A'+1;
    f=s2[2]-'A'+1;
    if(a==b){
        cout<<1;
        if(c==d){
            cout<<1;
            if(max(e,f)<=3||min(e,f)>=4){
                cout<<1;
                if(abs(e-f)==1){
                    cout<<1;
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
