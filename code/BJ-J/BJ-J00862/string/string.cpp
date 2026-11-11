#include<bits/stdc++.h>
using namespace std;
int a[200010];
string c[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int l=0;
    string s="";
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++)
        {
            s+=c[i];
        }
        l+=a[i];
    }
    int ans=0;
    for(long long i=0;i<l/2;i++)
    {
        if(s[i]!=s[l-1-i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}