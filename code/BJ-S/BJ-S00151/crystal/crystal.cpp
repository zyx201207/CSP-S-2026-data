#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[500005],ans,sum,s[500005];
//14:43:08暴力done
//14:46:52二分？yes
//14:48:09前缀和？no
//15:22:53二分终于条好了但是样例4一直是3834
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
        {cin>>a[i];}
    sort(a+1,a+n+1);
    
     for(int i=1;i<=n;i++)
     {
	 	int tm=m;
         int q=1;
         for(int j=i-1;j>=1;j--)
         {
             if(tm>=a[i]-a[j])
             {
                 tm-=(a[i]-a[j]);
                 q++;
             }
         }
         
         
         ans=max(ans,q);
     }
    cout<<ans;
    return 0;
}
