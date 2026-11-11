#include<bits/stdc++.h>
using namespace std;

int n,sum,ans,check;
int a[200009];
char b[200009];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << noboolalpha;
    cin>>n;
    cin>>a[0]>>b[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i]>>b[i];
        if(a[i]!=a[0])
        {
            check++;
        }
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    if(n==2)
    {
        if(b[0]==b[1])
        {
            cout<<0;
            return 0;
        }
        ans=min(a[0],a[1]);
        cout<<ans;
        return 0;
    }
    if(check==0)
    {
        for(int i=0;i<n/2;i++)
        {
            if(b[i]!=b[n-i-1])
            {
                check++;
            }
        }
        cout<<check*a[0];
        return 0;
    }
    cout<<a[n/2];
    return 0;
}
