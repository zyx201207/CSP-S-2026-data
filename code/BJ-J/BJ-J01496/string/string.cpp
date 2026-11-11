#include <bits/stdc++.h>
using namespace std;
long long n,cnt,l=0,r,ans=0,temp;
string s,a;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp>>a;
        for(int j=0;j<temp;j++)
        {
            s+=a;
            cnt++;
        }
    }
    r=cnt-1;
    while(l<=r)
    {
        if(s[l]!=s[r])
        {
            ans++;
        }
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}
