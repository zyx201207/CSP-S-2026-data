#include<bits/stdc++.h>
using namespace std;
int a[1000005];
char c[1000005];
vector<char>s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i];j++)
        {
            s.push_back(c[i]);
        }
    }
    int l=0,r=s.size()-1;
    long long ans=0;
    while(l<r)
    {
        if(s[l]!=s[r])
        {
            ans++;
        }
        l++;
        r--;
    }
    cout<<ans<<"\n";
}