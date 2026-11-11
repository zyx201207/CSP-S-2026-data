#include<bits/stdc++.h>
using namespace std;
bool check(string a)
{
    string a1=a;
    reverse(a.begin(),a.end());
    if(a1==a) return 1;
    else return 0;
}
void cnt(string a)
{
    string a1=a;
    long long ans=0;
    reverse(a.begin(),a.end());
    for(int i=0;i<=a.size()/2;i++)
    {
        if(a[i]!=a1[i]) ans++;
    }
    cout<<ans;
    return;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++)
    {
        int a;
        string c;
        cin>>a>>c;
        for(int j=1;j<=a;j++) s+=c;
    }
    if(check(s))
    {
        cout<<"0";
        return 0;
    }
    cnt(s);
    return 0;
}
