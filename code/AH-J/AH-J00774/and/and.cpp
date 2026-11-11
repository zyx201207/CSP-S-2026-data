#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m,maxx,a[N];
string s;
string to_two(ll x)
{
    string ss;
   string ch;
    while(x>0)
    {
        ch=x%2+'0';
        ss=ss+ch;
        x/=2;
    }
    while(ss.size()<4)ss=ss+"0";
    reverse(ss.begin(),ss.end());
    return ss;
}
string andd(string x,string y)
{
    string jj;
    if(x.size()>y.size())swap(x,y);
    while(x.size()<y.size())x=x+"0";
    for(ll i=0;i<s.size();i++)
    {
        if(x[i]!=y[i])jj[i]='0';
        else if(x[i]==y[i]&&x[i]=='0')jj[i]='0';
        else if(x[i]==y[i]&&x[i]=='1')jj[i]='1';
    }
    return jj;
}
int main()
{
    freopen("and.in","r",stdin)
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n==m)
    {
        for(ll i=1;i<=n;i++)cin>>a[i];
        s=to_two(a[1]);

        for(ll i=2;i<=n;i++)
        {
            to_string(a[i]);
            s=andd(s,to_string(a[i]));
        }
    }
    cout<<s;
    return 0;
}
