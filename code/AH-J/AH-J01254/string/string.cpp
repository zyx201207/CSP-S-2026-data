#include<bits/stdc++.h>
using namespace std;
int l,cnt=0;
int a[200005];
char ch[200005];
string s,c;
int main()
{
    freopen("string.in",r,stdin);
    freopen("string.out",w,stdout);
    cin>>l;
    for(int i=1;i<=l;i++)
    {
        cin>>a[i]>>ch[i];
        for(int i=1;i<=a[i];i++)
        {
            s[i]=ch[i];
        }
    }
    int x=s.size();
    for(int i=x;i>=1;i--)
    {
        c[i]==s[i];
    }
    for(int i=1;i<=x;i++)
    {
        if(c[i]!=s[i])cnt++;
    }
    cout<<cnt;
    return 0;
}
