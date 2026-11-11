#include<bits/stdc++.h>
using namespace std;
int c,s,cc,ss;
string sa,ssa;
int a[5];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>sa>>cc>>ssa;
    if(c==cc){
        s=(sa[0]-'0')*10+(sa[1]-'0');
        ss=(ssa[0]-'0')*10+(ssa[1]-'0');
        if(s==ss){
            if((sa[2]-'A'<=2&&ssa[2]-'A'<=2)||(sa[2]-'A'>=3&&ssa[2]-'A'>=3)){
                if(sa[2]-'A'>=3&&ssa[2]-'A'>=3){
                    cout<<"1111";
                    return 0;
                }
                if(sa[2]-'A'==1||ssa[2]-'A'==1){
                    cout<<"1111";
                    return 0;
                }else{
                    cout<<"1110";
                }
            }else{
                cout<<"1100";
                return 0;
            }
        }else{
            cout<<"1000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }

    return 0;
}
