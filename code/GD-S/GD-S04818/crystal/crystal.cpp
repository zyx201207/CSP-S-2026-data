#include<bits/stdc++.h>
using namespace std;
long long n,m,ma;
long long mi;
//int sj[500006] = {0};
long long mp[500006],cz[500006],cw[500006];
long long hs(long long x,long long y,long long ans)
{
	if(y>n)
	{
		return ans;
	}
	long long check;
	/*if(cz[y]-cz[x]-((x-1)*(mp[y]-mp[x]))>m)
	{
		//cout<<"x:"<<x<<" y:"<<y<<" ans:"<<ans<<endl;
		x++;
		check=hs(x,y,ans);
		ans=max(check,ans);
	}*/
	if(mp[y]/*+(sj[y]*m)*/<mp[x]/*+(sj[x]*m)*/)
	{
		x=y;
		y++;
	}
	else if(/*(sj[y]-sj[x])*m+*/(cz[y]-cz[x]-((x-1)*(mp[y]-mp[x])))>2*m)
	{
		x++;
		
	}
	else
	{
		//cout<<"x:"<<x<<" y:"<<y<<" ans:"<<ans<<endl;
		if(/*((sj[y]-sj[x])*m)*/+(cz[y]-cz[x]-((x-1)*(mp[y]-mp[x])))<=m)
		{
			ans=max(ans,y-x+1);
			
		}
		
		y++;
		
		
	}
	check=hs(x,y,ans);
	ans=max(check,ans);
	return ans;
}
/*long long run(long long x,long long mid,long long y,long long ans)
{
	
	long long check;
	for(int i=x;i<=y;i++)
	{
		if(mp[x]<=mp[mid]&&mp[y]<=mp[mid])
		{
			check=run(x,i,y,ans);
			ans=max(check,ans);
		}
		
	}
	
}*/
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cz[1]=0;
	scanf("%lld",&mp[1]);
	mi=mp[1];
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&mp[i]);
		if(mi<mp[i])
		{
			mi=mp[i];
		}
		//mp[i]+=mi;
		/*cz[i]=(mp[i]-mp[i-1])*(i-1)+cz[i-1];
		sj[i]=sj[i-1];
			if(cz[i]>m)
			{
				sj[i]++;
				cz[i]-=m;
			}
			else if(cz[i]<-m)
			{
				sj[i]--;
				cz[i]+=m;
			}
		*/
	}
	if(mi<0)
	{
		mi=mi*-1;
		
	}
	for(int i=1;i<=n;i++)
	{
		mp[i]+=mi;
		cz[i]=(mp[i]-mp[i-1])*(i-1)+cz[i-1];
		cw[i]=(mp[n-i]-mp[n-i+1])*(n-i+1)+cz[n-i+1];
		/*sj[i]=sj[i-1];
			if(cz[i]>m)
			{
				sj[i]++;
				cz[i]-=m;
			}
			else if(cz[i]<-m)
			{
				sj[i]--;
				cz[i]+=m;
			}*/
			 
	}
	ma=hs(1,1,0);
	cout<<ma;
	return 0;
} 
