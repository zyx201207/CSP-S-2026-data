#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
struct node
{
    long long l,r;
    char c;
};
vector<long long> a;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    vector<pair<long long,char>> t;
    vector<node>f,b;
    cin>>n;
    t.resize(n);
    f.resize(n);
    b.resize(n);
    long long x;
    char y;
    long long z=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        t[i-1]={x,y};
        z+=x;
    }
    long long p=0;
    for(int i=0;i<=t.size()-1;i++)
    {
        bool flag=(p<=z/2);int ppp=p;
        p+=t[i].first;
        if(p<=z/2-(z&1))
        {
            f[i]={ppp+1,p,t[i].second};
        }
        else if(flag)
        {
            f[i]={ppp+1,z/2-(z&1),t[i].second};
        }
        else
        {
            break;
        }
        a.push_back(ppp+1);
    }
    p=z+1;
    for(int i=t.size()-1;i>=0;i--)
    {
        bool flag=p>=z/2+1;int ppp=p;
        p-=t[i].first;
        if(p>=(z>>1)+1)
        {
            b[n-i+1]={z+1-ppp+1,z+1-p,t[i].second};
        }
        else if(flag)
        {
            b[n-i+1]={z+1-ppp+1,(z>>1)+1,t[i].second};
        }
        else
        {
            break;
        }
        a.push_back(z+1-ppp+1);
    }
    a.push_back((z>>1)+1);
    sort(a.begin(),a.end());
    int fp=0,bp=0;
    long long ans=0;
    for(int i=0;i<=a.size()-1;i++)
    {
        if(a[i]>0&&a[i]==a[i-1])
        {
            continue;
        }
        while(f[fp].l<=a[i])
        {
            fp++;
        }
        while(b[bp].l<=a[i])
        {
            bp++;
        }
        if(f[fp].c!=b[bp].c)
        {
            ans+=a[i+1]-a[i];
        }
    }
    cout<<ans;
}
