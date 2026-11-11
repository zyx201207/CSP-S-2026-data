#include<bits/stdc++.h>
using namespace std;
string ans="1110";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    bool tc=(a==c);
    bool tp=((b[0]==d[0])&&(b[1]==d[1]));
    char a1=b[2],a2=d[2];
    bool az=(a1=='A'||a1=='B'||a1=='C');
    bool bz=(a2=='A'||a2=='B'||a2=='C');
    bool az1=(a1=='D'||a1=='F');
    bool bz1=(a2=='D'||a2=='F');
    bool tcc=((az&&bz)||(bz1&&az1));
    bool pb=(az&&bz&&(abs((int)a1-(int)a2))==1)||(az1&&bz1);
    if(tc)cout<<1;
    else cout<<0;
    if(tc&&tp)cout<<1;
    else cout<<0;
    if(tc&&tp&&tcc)cout<<1;
    else cout<<0;
    if(tc&&tp&&tcc&&pb)cout<<1;
    else cout<<0;
    return 0;
}
