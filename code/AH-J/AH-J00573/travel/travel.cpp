#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    char sch1,sch2;
    cin>>c1>>s1>>sch1>>c2>>s2>>sch2;
    if(c1==c2) cout<<'1';
    else 
    {
        cout<<"0000"<<"\n";
        return 0;
    }
    if(s1==s2) cout<<'1';
    else 
    {
        cout<<"000"<<"\n";
        return 0;
    }
    if(sch1>sch2) swap(sch1,sch2);
    if((sch1>='A'&&sch2<='C')||(sch1=='D'&&sch2=='F')) cout<<'1';
    else 
    {
        cout<<"00"<<"\n";
        return 0; 
    }
    if((sch1=='A'&&sch2=='B')||(sch1=='B'&&sch2=='C')||(sch1=='D'&&sch2=='F')) cout<<'1';
    else 
    {
        cout<<'0'<<"\n";
        return 0;
    }
    cout<<"\n";
    return 0;
}