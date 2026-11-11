#include<bits/stdc++.h>
using namespace std;
#define Int long long
Int a[500005];
Int ans[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Int n,m;
    cin>>n>>m;
    bool flag=0;
    for(Int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1])
        {
            flag=1;
        }
    }
    if(m==1)
    {
        cout<<n;
    }
    else if(m==2)
    {
        Int q=a[n];
        for(Int i=1;i<=n;i++)
        {
            if(a[i]==q)
            {
                ans[q]++;
            }
            else{
                ans[1]++;
                ans[2]++;
            }
        }
        cout<<ans[1]<<' '<<ans[2];
    }
    else if(!flag){
        for(Int i=1;i<=n;i++)
        {
            ans[a[i]]=max(ans[a[i]],i);
        }
        for(Int i=1;i<=m;i++)
        {
            cout<<ans[i]<<' ';
        }
    }
    return 0;
}
/*
♖♘♗♕♔♗♘♖
♙♙♙♙♙♙♙♙




♟♟♟♟♟♟♟♟
♜♞♝♛♚♝♞♜
*/
