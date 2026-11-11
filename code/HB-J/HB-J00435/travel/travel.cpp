#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
bool check(string a,string b)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}
bool side(string a,string b)
{
    if(a>="A"&&a<="C")
    {
        if(b>="A"&&b<="C")
        {
            return 1;
        }
        return 0;
    }
    if(a=="F"||a=="D")
    {
        if(b=="F"||b=="D")
        {
            return 1;
        }
        return 0;
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    if(!check(r1,x1))
    {
        cout<<"0000";
        return 0;
    }
    cout<<1;
    string l=r2.substr(0,2);
    string l2=x2.substr(0,2);
    if(!check(l,l2))
    {
        cout<<"000";
        return 0;
    }
    cout<<1;
    string c=r2.substr(2,1);
    string c2=x2.substr(2,1);
    //cout<<"check:"<<side(c,c2)<<"\n";
    if(!side(c,c2))
    {
        cout<<"00";
        return 0;
    }
    cout<<1;
    int p=(int)r2[2];
    int q=(int)x2[2];
    if(max(p,q)-min(p,q)==1) cout<<1;
    else cout<<0;
    return 0;
}
