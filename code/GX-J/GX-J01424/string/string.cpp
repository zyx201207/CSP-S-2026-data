#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n,a[10000];
    char c[10000];
    string s1,s2;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            s1+=c[i];
        }
    }
    long long ans=0,q=0,p=s1.size();
    while(q!=p)
    {
        if(s1[q]!=s1[p])
        {
            ans++;
        }
        q++;
        p++;
    }
    cout<<ans;
    return 0;
}
