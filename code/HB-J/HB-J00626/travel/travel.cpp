#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b;
char p[5],q[5];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>p>>b>>q;
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(p[0]==q[0]&&p[1]==q[1]){
        cout<<1;
    }
    else {
        cout<<"000";
        return 0;
    }
    if(p[2]=='A'||p[2]=='B'||p[2]=='C'&&q[2]=='A'||q[2]=='B'||q[2]=='C'){
        cout<<1;
        if(abs(p[2]-q[2])==1)
        {
            cout<<1;
        }
        else cout<<0;
    }
    else if(p[2]=='D'||p[2]=='F'&&q[2]=='D'||q[2]=='F')
    {
        cout<<"11";
        return 0;
    }
    else{
        cout<<"00";
    }
    return 0;

}
