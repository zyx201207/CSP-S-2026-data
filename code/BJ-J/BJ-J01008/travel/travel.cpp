#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,s1,c2,s2;
char p1,p2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1;
    scanf("%lld%c",&s1,&p1);
    cin>>c2;
    scanf("%lld%c",&s2,&p2);
    if(c1==c2)
        cout<<1;
    else
        return cout<<"0000"<<endl,0;
    if(s1==s2)
        cout<<1;
    else
        return cout<<"000"<<endl,0;
    if(p1>='A'&&p1<='C'&&p2>='A'&&p2<='C'||p1>='D'&&p1<='F'&&p2>='D'&&p2<='F')
        cout<<1;
    else
        return cout<<"00"<<endl,0;
    if(p1=='A'&&p2=='B'||p2=='A'&&p1=='B'||p1=='B'&&p2=='C'||p2=='B'&&p1=='C'||p1=='D'&&p2=='F'||p2=='D'&&p1=='F')
        cout<<1<<endl;
    else
        return cout<<0<<endl,0;
    return 0;
}