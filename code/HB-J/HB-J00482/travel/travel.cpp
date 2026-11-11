#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    string a1,a2,b1,b2;
    a1=s1[0]+s1[1],a2=s1[2];
    b1=s2[0]+s2[1],b2=s2[2];
    if(c1==c2){
        cout<<1;
        if(a1==b1){
            cout<<1;
            if(a2<="C"&&b2<="C"||a2>="D"&&b2>="D"){
                cout<<1;
                if(a2=="A"&&b2=="C"||a2=="C"&&b2=="A"){
                    cout<<"0";
                    return 0;
                }else{
                    cout<<1;

                }
            }else{
                cout<<"00";
                return 0;
            }
        }else{
            cout<<"000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }
}

