#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string a,b,c,d;
bool check(char a){
    if(a>='A'&&a<='C') return 0;
    return 1;
}int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        if(b[0]==d[0]&&b[1]==d[1]){
            if(check(b[2])==check(d[2])){
                if((max(b[2],d[2])-1)==min(b[2],d[2])) cout<<"1111";
                else cout<<"1110";
            }else cout<<"1100";
        }else cout<<"1000";
    }else cout<<"0000";
    return 0;
}
