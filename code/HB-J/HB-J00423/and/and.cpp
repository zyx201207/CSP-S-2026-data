#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,maxl=-1,a[N];
string s[N];
string ans="-1";
int vis[N];
string ten2two(int x)
{
    string y;
    while(x!=0)
    {
        int c=x%2;
        char d=c+'0';
        y+=d;
        x=x/2;
    }
    int len=y.size();
    string z;
    for(int i=len-1;i>=0;i--)
    {
        z+=y[i];
    }
    return z;
}
string yu(string x,string y)
{
    string re;
    for(int i=0;i<maxl;i++)
    {
        if(x[i]=='1'&&y[i]=='1') re+='1';
        else re+='0';
    }
    return re;
}
int two2ten(string x)
{
    int p=1,re=0;
    for(int i=maxl-1;i>=0;i--)
    {
        int t=x[i]-'0';
        re+=t*p;
        p*=2;
    }
    return re;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxl=max((int)log2(a[i])+1,maxl);
        s[i]=ten2two(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int len=s[i].size();
        for(int j=1;j<=maxl-len;j++)
            s[i].insert(s[i].begin(),'0');
    }
    int sum=n;
    for(int i=0;i<maxl;i++)
    {
        if(sum==m) break;
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(s[j][i]=='1'&&vis[j]==0)
            {
                cnt++;
            }
        }
        if(cnt>=m)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[j][i]=='0')
                {
                    vis[j]=1;
                    sum--;
                }
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt==m) break;
        if(vis[i]==0)
        {
            cnt++;
            if(ans=="-1") ans=s[i];
            ans=yu(ans,s[i]);  
        }        
    }
    cout<<two2ten(ans);
    return 0;
}
