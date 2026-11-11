#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
int n;
long long a[N],ans,t;
string c,s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i =0;i<n;i++)
    {
        cin>>a[i]>>c[i];
        for (int j=0;j<a[i];j++)
        {
            s+=c[i];
        }
    }
    if (n==1)
    {
        cout<<'0';
        return 0;
    }
    int x=s.size()-1;
    for (int i=0;i<s.size()/2;i++)
    {
        if (s[i]!=s[x])
        {
            ans++;
        }
        x--;
    }
    cout<<ans;
    return 0;
}

