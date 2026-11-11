#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
string s,str;
int n,cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    str=s;
    for(int i=0;i<s.size();i++)
    {
        s[i]=str[s.size()-1-i];
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=str[i])
        {
            cnt++;
        }
    }
    cnt/=2;
    cout<<cnt;
    return 0;
}
