#include<bits/stdc++.h>

using namespace std;
#define int long long
int n,m,sum,ans,b=1000000000000000000,flag;
int a[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<n;i++)
        if(a[i]!=a[i+1])
            flag=1;
    if(flag==0){
        cout<<n;
        return 0;
    }
    
    flag=1;
    sort(a+1,a+n+1);
    int s=m;
    for(int i=1;i<n;i++)
    {
		m=s;
		flag=1;
        for(int j=0;j<n-i;j++){
			m=m-(a[i+j+1]-a[i+j])*(j+1);
			if(m<0) {ans=max(j+1,ans);flag=0;break;}
		}
		if(flag)
		ans=max(n-i+1,ans);
    }
    cout<<ans;
    return 0;
}
/*
5 5
1 2 4 8 9

16 8
-3 -1 2 2 2 2 2 2 2 2 22 2 2 2 2 7

5 8
-3 -1 2 2 7
*/
