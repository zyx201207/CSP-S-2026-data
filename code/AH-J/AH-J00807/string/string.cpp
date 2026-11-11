#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#define ll long long
using namespace std;
struct stu
{
	ll num,sumd;
	char c;
}a[10000086];
stu l[10000086],r[10000086];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,sum=0,jmid=0,ans=0,lenli,lenri;
	cin>>n;
	a[0]={0,0,' '};
	for(int i=1;i<=n;i++)
	{
		ll t1;char t2;
		cin>>t1>>t2;
		a[i]={t1,t1+a[i-1].num,t2};
		sum+=t1;
	}
	ll midpos=sum/2;
	jmid=(sum%2==0?0:1);
	if(jmid==1)
	{
		char midc;int midi;
		for(int i=1;i<=n;i++)
		{
			if(midpos<a[i].sumd)
			{
				midi=i-1;
				midc=a[midi].c;
			}
		}
		for(int i=1;i<midi;i++)
		{
			l[i]=a[i];
		}
		l[midi]={midpos-a[midi-1].sumd,midpos,midc};
		for(int i=n;i>midi;i--)
		{
			r[i]=a[i];
		}
		r[n-midi+1]={a[midi].num-1-(midpos-a[midi-1].sumd),a[midi].sumd,midc};
		lenli=midi;
		lenri=n-midi+1;
	}
	if(jmid==0)
	{
		char midcl,midcr;int midli,midri;
		for(int i=1;i<=n;i++)
		{
			if(midpos<a[i].sumd)
			{
				midri=i;
				midli=i-1;
				midcl=a[midli].c;
				midcr=a[midri].c;
			}
		}
		for(int i=1;i<midli;i++)
		{
			l[i]=a[i];
		}
		l[midli]={midpos-a[midli-1].sumd,midpos,midcl};
		for(int i=n;i>midli;i--)
		{
			r[i]=a[i];
		}
		r[n-midri+1]={a[midri].num-1-(midpos-a[midri-1].sumd),a[midri].sumd,midcr};
		lenli=midli;
		lenri=n-midri+1;
	}
	vector<stu> cut;
	ll trpos=1,mbpos=0,tri=0,pmbpos;
	for(int i=1;i<=lenli;i++)
	{
		pmbpos=mbpos;
		mbpos=l[i].sumd;
		if(tri>lenri) break;
		if(l[i].num<r[tri+1].num)
		{
			if(mbpos<r[tri+1].sumd)
			{
				if(r[tri+1].c!=l[i].c)
				{
					ans+=l[i].num;
				}
				trpos=mbpos;
				if(tri>lenri) break;
				continue;					
			}
			else
			{
				if(r[tri+1].c!=l[i].c)
				{
					ans+=r[tri+1].sumd-pmbpos;
				}
				if(r[tri+2].c!=l[i].c)
				{
					ans+=mbpos-r[tri+1].sumd;
				}
				tri++;
				if(tri>lenri) break;
				trpos=mbpos;
			}
		}
		else
		{
			if(r[tri+1].sumd<=mbpos)
			{
				while(r[tri+1].sumd<=mbpos)
				{
					tri++;
				if(tri>lenri) break;
					trpos=r[tri].sumd;
					if(r[tri].c!=l[i].c)
					{
						ans+=r[tri].num;
					}
				}
				if(r[tri].sumd==mbpos) continue;
			}
			if(r[tri+1].sumd>mbpos)
			{
				if(r[tri+1].c!=l[i].c)
				{
					ans+=r[tri+1].sumd-trpos;
				}
				if(r[tri+2].c!=l[i].c)
				{
					ans+=l[i].num-r[tri+1].sumd+trpos;
				}
				trpos=mbpos;
				tri++;
				if(tri>lenri) break;
			}
		}
	}
	cout<<ans;
	return 0;
}
