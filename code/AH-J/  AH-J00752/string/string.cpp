#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,cnt;
char a;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m>>a;
        for(int j=1;j<=m;j++)s+=a;
    }
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])  cnt++;
    }
    cout<<cnt;
    return 0;
}
