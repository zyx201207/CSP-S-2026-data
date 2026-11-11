#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2,c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>s1>>a2>>s2;
    if(a1==a2){
        cout<<1;
        b1=stoi(s1.substr(0,2)),b2=stoi(s2.substr(0,2));
        if(b1==b2){
            cout<<1;
            c1=s1[2]-'A',c2=s2[2]-'A';
            if(c1<3){
                if(c2>2)cout<<"00";
                else{
                    if(abs(c1-c2)==1)cout<<11;
                    else cout<<10;
                }
            }else{
                if(c2<3)cout<<"00";
                else{
                    if(abs(c1-c2)==1)cout<<11;
                    else cout<<10;
                }
            }
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
