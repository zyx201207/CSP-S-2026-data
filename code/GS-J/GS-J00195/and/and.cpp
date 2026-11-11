#include<bits/stdc++.h>

using namespace std;
const int N=2e5;
int a[N];
string s[N];
string sh;
int n,m,ans=INT_MIN;

void str (int z,int id)
{
    bool f=0;
    int cc=0;
    string ls;
    while(z)
    {
        ls+=z%2+'0';
        z/=2;
    }
    for(int i=ls.size()-1;i>=0;i--)
    {
        s[id]+=ls[i];
    }
}

string an(string s1,string s2)
{
    string s3;
    for(int i=min(s1.size(),s2.size())-1;i>=0;i--)
    {
        if(s1[i]=='1'&&'1'==s2[i])
        {
            s3+='1';
        }
        else  s3+='0';
    }
    return s3;
}

int hy(string s1)
{
    int as=0,er=1;
    for(int i=0;i<s1.size();i++)
    {
        as+=er*(s1[i]-'0');
        er*=2;
    }
    return as;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        str(a[i],i);
    }
    if(n==m)
    {
        sh=s[0];
       for(int i=1;i<n;i++)
       {
           sh=an(sh,s[i]);
       }
       cout<<hy(sh);
    }
    if(m==1)
    {
        sort(a,a+n);
        cout<<a[n-1];
        return 0;
    }
    if(m==2)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ans=max(ans,hy(an(s[i],s[j])));
            }
        }
        cout<<ans;
    }
    return 0;
}
