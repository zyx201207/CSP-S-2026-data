#include <bits/stdc++.h>
using namespace std;
bool flag(char s,char t)
{
    if((s=='A'&&t=='B')||(s=='B'&&t=='A')||(s=='B'&&t=='C')||(s=='C'&&t=='B')||(s=='D'&&t=='F')||(s=='F'&&t=='D'))
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s,s1,t,t1,ans="";
    cin >> s >> s1 >> t >> t1;
    int nums=0,numt=0;
    int nums1=0,numt1=0;
    int n=s.size(),n1=s1.size();
    int m=t.size(),m1=t1.size();
    for(int i=0;i < n;i++)
    {
        nums=nums*10+(s[i]-'0');
    }
    for(int i=0;i < m;i++)
    {
        numt=numt*10+(t[i]-'0');
    }
    for(int i=0;i < n1-1;i++)
    {
        nums1=nums1*10+(s1[i]-'0');
    }
    for(int i=0;i < m1-1;i++)
    {
        numt1=numt1*10+(t1[i]-'0');
    }
    char chs=s1[n1-1],cht=t1[m1-1];
    bool f1=0,f2=0,f3=0,f4=0;
    if(nums==numt)
    {
        ans+='1';
        f1=1;
    }
    else
    {
        ans+='0';
    }
    if(f1==1&&nums1==numt1)
    {
        ans+='1';
        f2=1;
    }
    else
    {
        ans+='0';
    }
    if(f1==1&&f2==1&&((chs<='C'&&cht<='C')||(chs>='D'&&cht>='D')))
    {
        ans+='1';
        f3=1;
    }
    else
    {
        ans+='0';
    }
    if(f1==1&&f2==1&&f3==1&&flag(chs,cht))
    {
        ans+='1';
        f4=1;
    }
    else
    {
        ans+='0';
    }
    cout << ans;
    return 0;
}
