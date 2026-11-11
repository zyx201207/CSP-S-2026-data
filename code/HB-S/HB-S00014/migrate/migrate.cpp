#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long a[1000005],b[1000005];
unsigned long long ansk=LONG_LONG_MAX,ans=0;
unsigned long long ans1=0,lq1=0,lq2=0;

void dfs(int x,int y,unsigned long long k)
{
	//cout<<x<<" "<<y<<" "<<k<<endl;
    if(x==y)
    {
        if(k<ansk)
        {
            ans=1;
            ansk=k;
        }else if(k==ansk) ans++;
        return;
    }
    for(int i=x+1;i<=y;i++)
    {
        if(b[i]-b[x]<=d)
        {
            dfs(i,y,k+1);
        }
    }
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
		ans1=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
			if(i==1) lq1=0;
            cin>>lq2;
            b[i]=lq2-lq1;
            lq1=lq2;
            b[i]+=b[i-1];
            for(int j=1;j<=i-2;j++)
            {
                ansk=-1;
                ans=0;
                dfs(j,i,0);
                if(ans==2) ans1++;
            }
        }
        cout<<ans1<<endl;
    }
}
