#include<iostream>
#define ll long long
using namespace std;
int c,T,n;
ll d,a[5000],length[5000];
int dfs(int st,int ed,int step,int len)
{
	int ans=0;
	if(step>len)return 0;
	if(a[ed]-a[st]<=d)
	{
		ans++;
		return ans;
	}
	for(int i=st;i<ed;i++)
	{
		if(a[ed]-a[i]<=d)ans+=dfs(i,ed,step+1,len);
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T>0)
	{
		int cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==0||c<=10)
		{
			for(int l=1;l<=n-3;l++)
			{
				for(int r=l+3;r<=n;r++)
				{
					if(a[r]-a[l]<=d)continue;
					int minchang=r-l;
					for(int i=2;i<=minchang;i++)
					{
						int ans=dfs(r,l,0,i);
						if(ans==2)cnt++;
						if(ans>0)break;
					}
				}
			}
			cout<<cnt<<endl;
		}
		if(c==11||c==12)
		{
			ll cha=a[2]-a[1];
			ll k=d/cha;
			cout<<n-2*k+1<<endl;
		}
		T--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 }
