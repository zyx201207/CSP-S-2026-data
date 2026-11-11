#include <bits/stdc++.h>
using namespace std;

int n,m;
string s,p;
bool pai=true;


int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>s>>m>>p;
    if(n==m){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }

    for(int i=0;i<=1;i++){
        if(s[i]!=p[i]) pai=false;
    }
    if(pai) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(s[2]=='A'||s[2]=='B'||s[2]=='C'){
        if(p[2]=='A'||p[2]=='B'||p[2]=='C')
            cout<<1;
        else{
            cout<<"00";
            return 0;
        }
    }
    if(s[2]=='D'||s[2]=='F'){
        if(p[2]=='D'||p[2]=='F')
            cout<<1;
        else{
            cout<<"00";
            return 0;
        }
    }
    if((s[2]==p[2]+1||s[2]==p[2]-1)&&((s[2]!='C'&&p[2]!='D')||(p[2]!='C'&&s[2]!='D'))){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
