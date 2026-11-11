#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c) cout<<"1";
    else cout<<"0";
    string e,f;
    e+=b[0],e+=b[1],f+=d[0],f+=d[1];
    if(e==f&&a==c) cout<<"1";
    else cout<<"0";
    char u=b[2],v=d[2];
    int x=(u>='A'&&u<='C')?1:2,y=(v>='A'&&v<='C')?1:2;
    if(x==y&&e==f&&a==c) cout<<"1";
    else cout<<"0";
    if(b[0]==d[0]&&b[1]==d[1]&&a==c){
        int g=b[2]-'A'+1,h=d[2]-'A'+1;
        if(g>=1&&g<=3&&h>=1&&h<=3&&abs(h-g)==1) cout<<"1";
        else if(g>=4&&h>=4&&abs(g-h)==2) cout<<"1";
        else cout<<"0";
    }else cout<<"0";
    return 0;
}