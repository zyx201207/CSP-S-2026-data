#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l,p;
char b[200005],q;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    string s="";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            s+=b[i];
        }
    }
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1]) l++;
    }
    cout<<l;
    return 0;
}
