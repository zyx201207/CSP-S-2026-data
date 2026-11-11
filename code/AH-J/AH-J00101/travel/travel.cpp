#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
unordered_map<char,int> ump={{'A',1},{'B',1},{'C',1},{'D',2},{'F',2}};
char a1,a2;
bool f(){
    if (a1=='A'&&a2=='B')
    {
        return true;
    }
    if (a1=='B'&&a2=='C')
    {
        return true;
    }
    if (a1=='D'&&a2=='F')
    {
        return true;
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    a1=s1.back();
    a2=s2.back();
    s1.pop_back();
    s2.pop_back();
    if (c1==c2)
    {
        cout<<1;
    }
    else
    {

        cout<<"0000";
        return 0;
    }
    if (s1==s2)
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if (ump[a1]==ump[a2])
    {
        cout<<1;
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if (f())
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
