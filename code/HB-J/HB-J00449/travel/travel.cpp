#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x,y;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>s1>>y>>s2;
    bool b1,b2,b3,b4;
    b1=(x==y);
    cout<<b1;
    int t1,t2;
    t1=(s1[0]-'0')*10+s1[1]-'0';
    t2=(s2[0]-'0')*10+s2[1]-'0';
    b2=(t1==t2);
    cout<<b1&&b2;
    char c1,c2;
    c1=s1[2],c2=s2[2];
    b3=(c1<='C'&&c2<='C')||(c1>='D'&&c2>='D');
    cout<<((b1&&b2)&&b3);
    int t3=abs(c1-c2);
    b4=!((c1=='C'&&c2=='D')||(c1=='D'&&c2=='C'));
    cout<<(((((t3==1)&&b1)&&b2)&&b3)&&b4);
    return 0;
}
