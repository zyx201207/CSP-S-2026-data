#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n,m;
int ans1=0;
bool vis[N];
long long qpow(long long a,long long b)
{
	long long res=1;
	while(b)
    {
        if(b&1)
        {
            res=res*a;
        }
        b>>=1;
        a=a*a;
    }
    return res;
}
void dfs(int cnt,int ans)
{
    if(cnt==m)
    {
        ans1=max(ans,ans1);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            dfs(cnt+1,(ans&a[i]));
            vis[i]=0;
        }
    }
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxn=-1e9;
    bool flag=true,ttt=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        bool flag1=false;
        for(int i=0;i<=20;i++)
        {
			if(a[i]==qpow(2,i)-1)
			{
				flag1=true;
			}
		}
		if(!flag1)
		{
			flag=false;
		}
		if(a[i]!=i-1)
        {
            ttt=false;
        }
    }
    if(m==1)//subtask 6
    {
        cout<<maxn<<endl;
        return 0;
    }
    if(m==n)//subtask 7
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=(ans&a[i]);
        }
        cout<<ans<<endl;
        return 0;
    }
    if(maxn<=4)//subtask 16,17
    {
        for(int i=4;i>=1;i--)
        {
            int cnt=0;
            for(int j=1;j<=n;j++)
            {
                if(a[j]==i)
                {
                    cnt++;
                    if(cnt>=m)
                    {
                        cout<<i<<endl;
                        return 0;
                    }
                }
            }
        }
        cout<<0<<endl;
        return 0;
    }
    if(n<=20||(m==2&&n<=5000))//subtask 1-5,8-10
    {
        memset(vis,0,sizeof(vis));
        dfs(0,qpow(2,20)-1);
        cout<<ans1<<endl;
        return 0;
    }
    if(flag)//subtask 13
    {
		sort(a+1,a+n+1);
		cout<<a[n-m+1]<<endl;
		return 0;
    }
    if(ttt)//subtask 14,15
    {
        cout<<n-m<<endl;
        return 0;
    }
    sort(a+1,a+n+1);//subtask 18,19
    long long num=qpow(2,30)-1;
    for(int i=n;i>=n-m+1;i++)
    {
        num=(num&a[i]);
    }
    cout<<num<<endl;
	return 0;
}