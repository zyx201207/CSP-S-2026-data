#include <bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
int a[mx];
string s[mx];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    cin>>n;
    string s1="";
    for(int i=0;i<n;i++) cin>>a[i]>>s[i];
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=a[i];j++) s1+=s[i];
    }
    int l=0,r=s1.size();
    cout<<s1<<'\n';
    while(l<=r)
    {
        if(s1[l]!=s1[r])
        {
            s1[r]=s1[l];
            ans++;
        }
        l++;r--;
    }
    cout<<ans;
    return 0;
}
