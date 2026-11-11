#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;int p1,p2,l1,l2;char w1,w2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000";
        return 0;
    }
    cout<<1;
    for(int i=0;i<s1.size()-1;i++) p1=p1*10+(s1[i]-'0'),p2=p2*10+(s2[i]-'0');
    w1=s1[s1.size()-1],w2=s2[s2.size()-1];
    if(w1=='D'||w1=='F') l1=2;
    else l1=1;
    if(w2=='D'||w2=='F') l2=2;
    else l2=1;
    if(p1!=p2)
    {
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(l1!=l2)
    {
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(abs(w2-w1)==1) cout<<1;
    else cout<<0;
    return 0;
}
