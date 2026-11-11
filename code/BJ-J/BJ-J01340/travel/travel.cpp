#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    int p1,p2;
    p1=int(s1[0]-'0')*10+int(s1[1]-'0');
    p2=int(s2[0]-'0')*10+int(s2[1]-'0');
    if(p1==p2) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    char a=s1[2],b=s2[2];
    if(a=='D'&&b=='F'||a=='F'&&b=='C') cout<<1;
    else if('A'<=a&&a<='C'&&'A'<=b&&b<='C') cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(max(int(a),int(b))-min(int(a),int(b))==1&&!(a=='C'&&b=='D'||a=='D'&&b=='C')) cout<<1;
    else cout<<0;
    return 0;
}
