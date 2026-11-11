#include<bits/stdc++.h>
using namespace std;
int r,x;
string s_r,s_x;
bool flag=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>r>>s_r>>x>>s_x;
    if(r==x)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s_x[0]==s_r[0]&&s_x[1]==s_r[1])cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(s_r[2]=='F'&&s_x[2]=='D'||s_r[2]=='D'&&s_x[2]=='F'){
        flag=1;
        cout<<1;
    }
    else if(s_r[2]=='A'&&(s_x[2]=='B'||s_x[2]=='C')) cout<<1;
    else if(s_r[2]=='B'&&(s_x[2]=='A'||s_x[2]=='C')) cout<<1;
    else if(s_r[2]=='C'&&(s_x[2]=='B'||s_x[2]=='A')) cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(flag||(s_r[2]=='B'||s_x[2]=='B'))cout<<1;
    else cout<<0;
    return 0;
}
