#include<bits/stdc++.h>
using namespace std;
int n,m,beg=1,ans=0;
struct node{int w,pre,nxt;}t[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i].w);
		t[i].pre=i-1,t[i].nxt=i+1;
	}
	for(int i=29;i>=0;i--)
	{
		int cnt=0,now=beg;
		while(now<=n)
		{
			if(t[now].w&(1<<i))cnt++;
			now=t[now].nxt;
		}
		if(cnt>=m)
		{
			ans+=(1<<i);now=beg;
			while(now<=n)
			{
				if((t[now].w&(1<<i))==0)
				{
					if(now==beg)beg=t[now].nxt;
					t[t[now].pre].nxt=t[now].nxt;
					t[t[now].nxt].pre=t[now].pre;
				}
				//else cout<<(1<<i)<<" "<<ans<<" "<<t[now].w<<endl;
				now=t[now].nxt;
			}
		}
	}
	printf("%d",ans);
}
