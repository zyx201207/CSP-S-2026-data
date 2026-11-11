#include<bits/stdc++.h>
using namespace std;
long long n,t,d,c;
string s,ss;
char a;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t>>a;
        for(long long j=1;j<=t;j++) s+=a;
    }
    d=s.size();
    if(d==1 || s==ss)
    {
        cout<<0;
        return 0;
    }
    ss=s;
    reverse(s.begin(),s.end());
    for(long long i=0;i<d/2;i++)
    {
        if(s[i]!=ss[i]) c++;
    }
    cout<<c;
    return 0;
}
