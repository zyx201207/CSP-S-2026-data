#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,x1,y1;
    string x,y;
    char n,m;
    cin>>a>>x>>b>>y;
    x1=(x[0]-'0')*10+x[1]-'0';
    y1=(y[0]-'0')*10+y[1]-'0';
    n=x[2];
    m=y[2];
    //<<a<<' '<<b<<' '<<n<<' '<<m<<' '<<x1<<' '<<y1;
    if(a==b)cout<<1;
    else cout<<0;
    if(a==b&&x1==y1)cout<<1;
    else cout<<0;
    if(a==b&&x1==y1&&((n>='D'&&m>='D')||(n<='C'&&m<='C')))cout<<1;
    else cout<<0;
    if(a==b&&x1==y1&&n-m==1||m-n==1&&((n>='D'&&m>='D')||(n<='C'&&m<='C')))cout<<1;
    else cout<<0;
    return 0;
}
