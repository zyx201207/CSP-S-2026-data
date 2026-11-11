#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];

map<long long,string>mp;
string change(int x)
{
    string b="";
    while(x>0)
    {
        char c=' ';
        if(x%2==1)
        {

            c='1';
        }
        else{
            c='0';
        }
        b=c+b;
        x/=2;
    }
    return b;
}
int cmp(int x,int y)
{
    return x>y;
}
int anw(string a,string b)
{
    int num=0;
    int cnt=1;
    int len=max(a.size(),b.size());
    string c="";
    while(len-a.size()>0)
    {
        a='0'+a;
    }
    while(len-b.size()>0)
    {
        b='0'+b;
    }
    for(int i=len-1;i>=0;i--)
    {
        if(a[i]==b[i])
        {
            num+=cnt;
        }
        cnt*=2;
    }
    for(int i=0;i<=c.size();i++)
    {
        if(c[i]=='1')
        {
            num+=cnt;
        }
        cnt*=2;
    }
    return num;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        mp[i]=change(a[i]);

    }
    long long ans=anw(mp[1],mp[2]);

    for(int i=2;i<m;i++)
    {
        ans+=anw(change(ans),mp[i+1]);
    }
    cout<<ans<<endl;
    return 0;
}
