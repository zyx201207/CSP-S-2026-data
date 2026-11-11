#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int n,m,a[N],d[N],maxn=INT_MIN,cnt;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int num=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
    	if(m-((a[i]-a[i-1])*(cnt)+num)>=0)
    	{
    		num+=(a[i]-a[i-1])*(cnt),cnt++;
		}else{
			while(1)
			{
				if(m-((a[i]-a[i-1])*(cnt)+num)<0)
				{
					num-=(a[i-1]-a[i-cnt]);
					cnt--;
				}else{
					num+=(a[i]-a[i-1])*(cnt),cnt++;
					break;
				}
			}
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn<<endl;
    return 0;
}
