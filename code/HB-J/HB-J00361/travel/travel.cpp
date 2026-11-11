#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    string bl="",dl="";
    bl+=b[0],bl+=b[1],dl+=d[0],dl+=d[1];
    if(bl!=dl){
        cout<<"1000";
        return 0;
    }
    int br=b[2]-'A',dr=d[2]-'A';
    if((br<=2&&dr>2)||(br>2&&dr<=2)){
        cout<<"1100";
        return 0;
    }
    if(abs(br-dr)!=1){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
