#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long

/*substr(0,s.size()/2) 奇长度前半段
  substr(s.size()/2+1) 奇长度后半段
  substr(0,s.size()/2) 偶长度前半段
  substr(s.size()/2) 偶长度后半段
*/
ll n;
string rev(string s)
{
    string ss=s;
    reverse(ss.begin(),ss.end());
    return ss;
}
ll diff(string s1,string s2)
{
    ll sum=0;
    for(ll i=0; i<s1.size(); i++)
    {
        sum+=(s1[i]!=s2[i]);
    }
    return sum;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s="";
    cin>>n;
    ll a;
    char c;
    for(ll o=1; o<=n; o++)
    {
        cin>>a>>c;
        if(n*a>((ll)1e8))
        {
            cout<<"0";
            return 0;
        }
        while(a--)
        {
            s+=c;
        }
    }
    string bg,ed;
    if(!(s.size()%2))
    {
        bg=s.substr(0,s.size()/2);
        ed=s.substr(s.size()/2);
    }
    else
    {
        bg=s.substr(0,s.size()/2);
        ed=s.substr(s.size()/2+1);
    }
    string f_bg=rev(bg);
    string f_ed=rev(ed);
    ll dif1=diff(f_bg,ed);
    ll dif2=diff(bg,f_ed);
    cout<<min(dif1,dif2);
    return 0;
}
/*
  RP++
  AC++
  AK++
*/
