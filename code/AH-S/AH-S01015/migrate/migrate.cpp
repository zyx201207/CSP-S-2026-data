#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[200010],b[200010],ans,r[200010],tmp,num[200010],ou;
queue<long long>q;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t)
	{
		if(c==11||c==12)
		{
			cin>>n>>d;
			for(long long i=1;i<=n;i++)cin>>a[i];
			b[1]=d/(a[2]-a[1]);
			ans=n-(b[1]*2)+1;
			if(ans>=0)cout<<ans<<'\n';
			else cout<<"0";
			t--;
			continue;
		}
		cin>>n>>d;
		for(long long i=1;i<=n;i++)cin>>a[i];
		for(long long i=1;i<=n;i++)
		{
			b[i]=0;
			for(long long j=i+1;j<=n;j++)
			{
				if((a[j]-a[i])<=d)b[i]++;
				else break;
			}
		}
		ou=0;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i;j<=n;j++){r[j]=0x3f3f3f3f3f3f3f3f;num[j]=0;}
			
			r[i]=0;
			q.push(i);
			while(!q.empty())
			{
				tmp=q.front();
				q.pop();
				for(long long j=1;j<=b[tmp];j++)
				{
					if(r[tmp]+1<r[tmp+j])
					{
						r[tmp+j]=r[tmp]+1;
						q.push(tmp+j);
					}
					if(r[tmp]+1==r[tmp+j])num[tmp+j]++;
				}
			}
			for(long long j=i;j<=n;j++)if(num[j]==2){ou++;}
		}
		cout<<ou<<'\n';
		t--;
	}
	return 0;
}
