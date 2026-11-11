#include<bits/stdc++.h>
#include<cstring>
#include<string>
#include<map>
using namespace std;
string c1,s1,c2,s2;
map<char,int> mapp;
bool check(char ch1,char ch2)
{
    if(ch1=='A'&&ch2=='B')
        return true;
    if(ch1=='B'&&ch2=='c')
        return true;
    if(ch1=='D'&&ch2=='F')
        return true;
    return false;
}
signed main()
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
    string e,r;
    for(int i=0;i<=1;i++)
        e+=s1[i],r+=s2[i];
    if(e!=r)
    {
        cout<<"000";
        return 0;
    }
    cout<<1;
    mapp['A']=mapp['B']=mapp['C']=1;
    mapp['D']=mapp['F']=2;
    if(mapp[s1[2]]!=mapp[s2[2]])
    {
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(check(s1[2],s2[2])==false&&check(s2[2],s1[2])==false)
        cout<<0;
    else
        cout<<1;
    return 0;
}
