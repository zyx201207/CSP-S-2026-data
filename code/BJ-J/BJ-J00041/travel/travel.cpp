#include<iostream>
#include<cmath>
using namespace std;
bool in(char a){
    return a=='A'||a=='B'||a=='C';
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    if(b[0]!=d[0]||b[1]!=d[1]){
        cout<<"000";
        return 0;
    }
    cout<<"1";
    if(!in(b[2])&&in(d[2])||in(b[2])&&!in(d[2])){
        cout<<"00";
        return 0;
    }
    cout<<"1";
    if(!in(b[2])&&!in(d[2])) cout<<"1";
    else if(abs(b[2]-d[2])==1) cout<<"1";
    else cout<<"0";
    return 0;
}
