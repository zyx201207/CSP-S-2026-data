#include<bits/stdc++.h>
using namespace std;
#define int long long
int as(string rj)
{
	string qb;
	string hb;
	for(int i=0;i<rj.size();i++)
	{
		if(rj.size()%2==0)
		{
			for(int i=0;i<rj.size()/2;i++)
			{
				qb+=rj[i];
			}
			for(int j=rj.size();j>rj.size()/2+1;j--)
			{
				hb+=rj[j];
			}
			if(qb==hb)return 1;
			else return 0;
		}
		else if(rj.size()%2!=0)
		{
			for(int i=0;i<rj.size()/2;i++)
			{
				qb+=rj[i];
			}
			for(int j=rj.size();j>rj.size()/2+2;j--)
			{
				hb+=rj[j];
			}
			if(qb==hb)return 1;
			else return 0;
		}
	}
	return 1;
}
struct node{
	int k;
	string s;
}t[20000020];
signed main(){
	freopen(string.in,"r",stdin);
	freopen(string.out,"w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].k >>t[i].s ;
	}
	string dd;
	for(int i=0;i<=n;i++)
	{
		for(int i=1;i<=t[i].k;i++){
			dd+=t[i].s;
		}
	}
	int cnt=0;
	if(as(dd)==1)
	{
		cout<<0;
	}
	else if(as(dd)!=1)
	{
		while(as(dd)==0)
		{
			for(int i=0;i<dd.size();i++)
			{
				for(int j=dd.size();j>0;i--)
				{
					if(dd[i]!=dd[j])
					{
						dd[i]=dd[j];
						cnt++;
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
