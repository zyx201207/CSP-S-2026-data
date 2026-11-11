#include <bits/stdc++.h>

using namespace std;

string change(int a)
{
    int ppp=a;
    string s1="";
    string s2="";
    while(ppp!=1)
    {
        s1+='0'+ppp%2;
        ppp/=2;
    }
    s2+='1';
    for(int i=0;i<s1.size();i++)
        s2+=s1[i];
    return s2;
}
int andd (string s1,string s2)
{
    string s3="";
    int n=max(s1.size(),s2.size());
    int cnt=0,cs=0;
    if(s1.size()<s2.size())
    {
        int m=s1.size()-s2.size();
        for(int i=0;i<m;i++)
            s3+='0';
    }
    else
    {
        int m=s2.size()-s1.size();
        for(int i=0;i<m;i++)
            s3+='0';
    }
    s3+=s1;
    swap(s1,s3);
    s3="";
    for(int i=0;i<n;i++)
        if(s1[i]==s2[i] && s1[i]=='1')
            s3[i]='1';
        else
            s3[i]='0';
    for(int i=s3.size();i>=0;i--)
        if(s3[i]=='1')
        {
            cnt+=pow(cs,2);
            cs++;
        }
    return cnt;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w",stdout);

    int n,m;
    cin>>n>>m;
    string p[n];
    for(int i=0;i<n;i++)
    {
        int j;
        cin>>j;
        p[i]=change(j);
    }
    for(int i=0;i<n;i++)
    {
        int maxx=max(andd(p[i],p[i+1]));
    }
    cout<<maxx;
    return 0;
}
