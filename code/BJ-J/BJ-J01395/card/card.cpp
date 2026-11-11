#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1])
        {
            cnt++;
        }
        else
        {
            cnt+=1;
            cout<<cnt<<" ";
        }
    }
    return 0;
}
