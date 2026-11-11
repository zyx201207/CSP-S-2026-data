#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
string er(int a)
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    char t;
    string b;
    while(a!=0)
    {
        b+=a%2+'0';
        a/=2;
    }
    for(int i=0;i<b.size()/2;i++)
    {
        t=b[i];
        b[i]=b[b.size()-i-1];
        b[b.size()-i-1]=t;
    }
}
int yu(string a,string b)
{
    string c;
    for(int i=0;i<min(a.size(),b.size());i++)
    {
        if(a[i]==b[i])
            c+=a;
        else
            c+='0';
    }
    int cnt=0,n;
    for(int i=0;i<c.size();i++)
    {
        n=1;
        for(int j=i+1;j<c.size();j++)
            n*=2;
        cnt+=n;
    }
    return cnt;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a;
    string b[n];
    int cnt[2];
    cnt[1]=0;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        b[i]=er(a);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            cnt[0]=yu(b[i],b[j]);
            if(cnt[1]<cnt[0])
                cnt[1]=cnt[0];
        }
    }
    cout<<cnt[1];
    return 0;
}