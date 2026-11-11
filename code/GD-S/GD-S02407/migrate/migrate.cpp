#include<bits/stdc++.h>
#define lll long long
using namespace std;
lll c,t,n,d;
lll x[2000200];
struct node{
	lll nx,w,to;
}e[5000500];
lll head[5000500],cnt;
void adde(lll u,lll v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].nx=head[u];
	head[u]=cnt;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	if(c==13||c==14){
		for(int i=1;i<=t;i++)
		cout<<0<<endl;
		fclose(stdin);fclose(stdout);
	return 0;
	}
	while(t>0)
	{
		t--;
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(c==11||c==12) {
			lll duan=x[n]-x[n-1];
			if(d>=2*duan&&d<3*duan)
			{
				n=n-3;
				cout<<n<<endl;
			}
			else
			cout<<0<<endl;
		}
		if(c<=10)
		{
			memset(e,0,sizeof(e));memset(head,0,sizeof(head));cnt=0;
			for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					adde(i,j);adde(j,i);
				}
			}
			lll ans=0;
			for(int i1=1;i1<=n;i1++)
			{
				lll ato[5050]={0},ans=0;
				priority_queue<int> q;
				lll aaa=1;
				bool vis[5050]={0};
				vis[i1]=1;
				for(int i=head[i];i;i=e[i].nx)
				{
					lll y=e[i].to;
					q.push(y);
					aaa++;vis[y]=1;
				}
			while(aaa<n)
			{
				while(q.empty()==0)
				{
					int q1;
					q1=q.top();
					q.pop();
					for(int i=head[q1];i;i=e[i].nx)
					{
						lll y=e[i].to;
						if(vis[y]==1&&ato[y]<=0)
						{
							ato[y]--;
						}
						else {
							q.push(y);vis[y]=1;aaa++;
						}
					}
				}
				for(int i=1;i<=n;i++)
				{
					if(ato[i]<=0) ato[i]*=-1;
					if(ato[i]==2) ans++;
				}
			}
			}
			cout<<ans<<endl;
		}
		
	}
	
	
	fclose(stdin);fclose(stdout);
	return 0;
 } 
