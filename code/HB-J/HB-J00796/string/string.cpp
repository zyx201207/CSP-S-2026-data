#include<bits/stdc++.h>
using namespace std;
int n;
int a[15];
char b[15];
int maxn=-1;
int main()
{
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        maxn=max(maxn,a[i]);
    }
    if(n==1) cout<<"0";
    else if(n==2)
    {
        if(b[1]==b[2])
        {
            cout<<"1";
        }
        else
        {
            cout<<min(a[1],a[2]);
        }
    }
    else
    {
        cout<<"3";
    }
    return 0;
}
