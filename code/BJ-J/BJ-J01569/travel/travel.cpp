#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool que1(string cu,string cv)
{
    if(cu[0]==cv[0] && cu[1]==cv[1]) return 1;
    else return 0;
}
bool que2(string cu,string su,string cv,string sv)
{
    if(!que1(cu,cv)) return 0;
    if(su[0]==sv[0] && su[1]==sv[1]) return 1;
    return 0;
}
bool que3(string cu,string su,string cv,string sv)
{
    if(!que2(cu,su,cv,sv)) return 0;
    if((su[2]>='A' && su[2]<='C') && (sv[2]>='A' && sv[2]<='C')) return 1;
    if((su[2]=='D' || su[2]=='F') && (sv[2]=='D' || sv[2]=='F')) return 1;
    return 0;
}
bool que4(string cu,string su,string cv,string sv)
{
    if(!que3(cu,su,cv,sv)) return 0;
    if((su[2]=='C' && sv[2]=='A') || (su[2]=='A' && sv[2]=='C')) return 0;
    return 1;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    cout<<que1(c1,c2)<<que2(c1,s1,c2,s2)<<que3(c1,s1,c2,s2)<<que4(c1,s1,c2,s2)<<endl;
    return 0;
}