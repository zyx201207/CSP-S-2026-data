#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c) cout<<1;
    else {
        cout<<"0000";
        return 0;
    }
    int x=(b[0]-'0')*10+(b[1]-'0'),y=(d[0]-'0')*10+(d[1]-'0');
    if(x==y){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    char p=b[2],q=d[2],f=0;
    if(p>='A'&&p<='C'&&q>='A'&&q<='C') cout<<1;
    else if(p>='D'&&p<='F'&&q>='D'&&q<='F') cout<<1;
    else {
        cout<<"00";
        return 0;
    }
    if(abs((q-'0')-(p-'0'))==1)
    {
        cout<<1;
    }
    else cout<<0;
    return 0;
}
