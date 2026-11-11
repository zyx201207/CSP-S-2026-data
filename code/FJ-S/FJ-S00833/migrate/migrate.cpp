#include<bits/stdc++.h>
using namespace std;
int b[2000005],e[2000005],k,t,n;
long long a[2000005],c[2000005],m,r,h,f;
struct jgt
{
	int x,y;
}tt;
queue<jgt>q;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	cin>>k;
	if(1)
	{
		cin>>t;
		while(t--)
		{
			memset(b,0,sizeof(b));
			f=0;cin>>n>>m;
			for(int s=1;s<=n;s++)cin>>a[s];			
			r=0;h=0;
			int l=0;
			for(int s=1;s<=n;s++)
			{
				while(h+a[r+1]-l<=m&&r<n)
				{
					r++;
					h+=a[r];
				}
				b[s]=r;
				l+=a[s];
			}				
			memset(c,0x3f3f3f3f,sizeof(c));
			c[1]=0;
			for(int s=1;s<=n;s++)
			{
				for(int d=s+1;d<=b[s];d++)
				{
					c[d]=min(c[d],c[s]+1);
				}
			}
			for(int g=1;g<=n;g++)
			{
				q.push({g,0});
				while(!q.empty())
				{
					tt=q.front();
					q.pop();
					e[tt.x]++;
					for(int s=tt.x+1;s<=b[tt.x];s++)
					{
						if(tt.y+1==c[s])
						{
							q.push({s,tt.y+1});
						}
						else break;
					}
				}
				for(int s=g;s<=n;s++)f+=(e[s]==2);
			}
			cout<<f<<endl;
		}

	}
	return 0;
}
