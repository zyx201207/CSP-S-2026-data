#include<bits/stdc++.h>
using namespace std;
int n,m,a[10],cnt;
int main()
{
    freopen("crystal.in","r",in);
    freopen("crystal.out","w",out);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        a[i]++;
        if(a[i]==a[1])
        {
            cnt++;
        }   
    }
    cout<<cnt;
    return 0;
}

