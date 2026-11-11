#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n[200];
    n[int('A')]=1;
    n[int('B')]=1;
    n[int('C')]=1;
    n[int('D')]=2;
    n[int('F')]=2;
    string s1,s2,p1,p2;
    cin>>s1>>p1>>s2>>p2;
    if(s1==s2)cout<<1;
    else
    {
        cout<<0;
    }
    if(p1[0]==p2[0]&&p1[1]==p2[1]&&s1==s2)cout<<1;
    else
    {
        cout<<0;
    }
    if(n[p2[2]]==n[p1[2]]&&p1[0]==p2[0]&&p1[1]==p2[1]&&s1==s2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(abs(p2[2]-p1[2])==1&&p1[0]==p2[0]&&p1[1]==p2[1]&&s1==s2&&n[p2[2]]==n[p1[2]])
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
