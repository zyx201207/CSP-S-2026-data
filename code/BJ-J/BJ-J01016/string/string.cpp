#include<bits/stdc++.h>
using namespace std;
int a[200000001];
char c[200000001];
string s;
int main()
{
    int n,cnt=0;
    long long wei=0;
    string s="",s1="",s2="";
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        wei+=a[i];
        for(int j=1;j<=a[i];j++)s+=c[i];
    }
    for(int i=0;i<=wei/2;i++)
    {
        if(s[i]!=s[wei-1-i])cnt++;
    }
    cout<<cnt;
}
