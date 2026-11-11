#include<bits/stdc++.h>
using namespace std;
int n,ans;
char a[1000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int ans2=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        char c;
        cin>>x>>c;
        for(int i=1;i<=x;i++)
        {
            a[++ans2]=c;
        }
    }
    for(int i=1;i<=ans2/2;i++)
    {
        if(a[i]!=a[ans2+1-i])
        {
            ans++;
        }
    }
    cout<<ans;
}
