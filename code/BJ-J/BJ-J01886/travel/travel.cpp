#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
using namespace std;
string a,b,c,d;
bool b1=0,d1=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travle.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    if(b[0]!=d[0]||b[1]!=d[1]){
        cout<<"1000";
        return 0;
    }
    if(b[2]=='A'||b[2]=='B'||b[2]=='C')
        b1=1;
    if(d[2]=='A'||d[2]=='B'||d[2]=='C')
        d1=1;
    if(d1!=b1){
        cout<<"1100";
        return 0;
    }
    if(d1!=0&&b[2]=='A'&&d[2]=='C'||d1!=0&&d[2]=='A'&&b[2]=='C'){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}