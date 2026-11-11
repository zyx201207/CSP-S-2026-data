#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a==b)cout<<1;
    else {
        cout<<0<<0<<0<<0;
        return 0;
    }
    int x,y;
    x=(c[0]-'0')*10+(c[1]-'0');
    y=(d[0]-'0')*10+(d[1]-'0');
    char p,q;
    if(x==y)cout<<1;
    else {
        cout<<0<<0<<0;
        return 0;
    }
    p=c[2];
    q=d[2];
    if((p<='C'&&q<='C')||(p>='D'&&q>='D'))cout<<1;
    else {
        cout<<0<<0;
        return 0;
    }
    if((p+1==q||q+1==p)&&((p!='C'&&q!='D')||(p!='D'&&q!='C')))cout<<1;
    else cout<<0;
    return 0;
}
