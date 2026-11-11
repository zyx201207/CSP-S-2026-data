#include<bits/stdc++.h>
#define iu long long
using namespace std;
iu n,m,a[500010],b[500010],ans=-999999,cnt,tmp;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	memset(b,0x3f,sizeof(b));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		tmp=1;
		cnt=0;
		for(int j=i;j>=2;j--)
		{
			if(cnt+a[i]-a[j-1]>=m)
			{
				if(cnt+a[i]-a[j-1]==m)
				{
					cnt+=a[i]-a[j-1];
					tmp++;
				}
				//cout<<i<<' '<<ans<<' '<<tmp<<'\n';
				ans=max(ans,tmp);
				break;
			}else{
				cnt+=a[i]-a[j-1];
				tmp++;
			}	
		}
	}
	cout<<ans;
	return 0;
}
