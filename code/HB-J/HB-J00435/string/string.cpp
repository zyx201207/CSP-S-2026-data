#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int n,a[N];
ll cnt=0;
char c[N];
string s;
map<char,int> mp;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        mp[c[i]]++;
    }
    if(mp.size()==1)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        while(a[i]--)
        {
            s+=c[i];
        }
    }
    ll len=s.size();
    for(int i=0;i<len/2;i++)
    {
        if(s[i]!=s[len-i-1])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
