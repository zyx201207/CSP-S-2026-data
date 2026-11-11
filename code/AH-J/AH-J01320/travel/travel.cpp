#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
    }else if(b[0]!=d[0]||b[1]!=d[1]){
        cout<<"1000";
    }else{
        char x=b[2];
        char y=d[2];
        if((x<='C'&&y>'C')||(x>'C'&&y<='C')){
            cout<<"1100";
        }else if(abs(x-y)!=1){
            cout<<"1110";
        }else{
            cout<<"1111";
        }
    }
    return 0;
}
