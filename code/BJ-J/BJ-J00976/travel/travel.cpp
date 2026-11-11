#include<bits/stdc++.h>
using namespace std;
struct ticket{
    int cc,num;
    char s=' ';
}x,y;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>a>>b>>c>>d;
    x.cc=(a[0]-'0')*10+(a[1]-'0');
    y.cc=(c[0]-'0')*10+(c[1]-'0');
    x.num=(b[0]-'0')*10+(b[1]-'0');
    y.num=(d[0]-'0')*10+(d[1]-'0');
    x.s=b[2];
    y.s=d[2];
    if(x.cc==y.cc) cout<<1;
    else{
        cout<<"0000\n";
        return 0;
    }
    if(x.num==y.num) cout<<1;
    else{
        cout<<"000\n";
        return 0;
    }
    if(x.s<='C'&&y.s<='C') cout<<1;
    else{
        cout<<"00\n";
        return 0;
    }
    if(abs(x.s-y.s)==1) cout<<1;
    else cout<<0;
    cout<<'\n';
    return 0;
}//Luogu:Louis__2013