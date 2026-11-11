#include<bits/stdc++.h>
using namespace std;
char ch[1000010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long s,ans=0;
    char c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s>>c;
        for(int i=1;i<=s;i++)
            ch[i]=c;
    }
    int ns=n/2;
    while(ns)
    {
        if(ch[ns]!=ch[n-ns+1])
            ans++;
        ns--;
    }
    cout<<ans<<endl;
    return 0;
}
