#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using ll=long long;
ll n,a[N];
ll sum,ans;
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		char _;
		cin>>a[i]>>_;	
		c[i]=_;	
		sum+=a[i];
	}
	if(sum%2)
	{
		const ll mid=sum/2+1;
		ll t=mid,t1=mid;
		ll le[N]={0},ri[N]={0},li=0,rj=0,lq=0,rq=0;
		string l,r;
		bool flag;
		for(ll i=1;i<=n;++i)
		{
			if(t-a[i]>0||flag==1)
			{
				t-=a[i];
				if(!flag)
				{
					le[++li]=a[i];
					lq+=a[i];
					l[li]=c[i];
				}
				else
				{

					ri[++rj]=a[i];
					rq+=a[i];
					r[rj]=c[i];
				}
				
			}
			else if(flag==0)
			{
				flag=1;
				//a[i]-t;
				le[++li]=t1-1-lq;
				l[li]=c[i];
				ri[++rj]=a[i]-(t1-1-lq)-1;
				r[rj]=c[i];
			}
		//	cout<<"\n\n\n\n\n\n\n\n";
		//	cout<<'\n'<<a[i]<<' '<<c[i]<<'\n';
		//	cout<<"\n\n\n\n\n\n\n\n";
		//	for(int i=1;i<=li;++i)
		//	{
			//	cout<<le[i]<<' '<<l[i]<<'\n';
			//}
			//cout<<'\n';
			//for(int i=1;i<=rj;++i)
			//{
			//	cout<<ri[i]<<' '<<r[i]<<'\n';
			//}
		}
		pair<ll,char>te1={le[li],l[li]},te2={ri[1],r[1]};
		ll lw=li,rw=1;
		while(1)
		{
			//cout<<'\n'<<ans;
			//cout<<"\n\n"<<te1.first<<' '<<te1.second<<"\n"<<te2.first<<' '<<te2.second;
			pair<ll ,char>nt1,nt2;
			if(te1.second==te2.second)
			{
				if(te1.first>te2.first)
				{
					nt1={te1.first-te2.first,te1.second};
					rw+=1;
					nt2={ri[rw],r[rw]};
				}
				else if(te2.first>te1.first)
				{
					nt2={te2.first-te1.first,te2.second};
					lw-=1;
					nt1={le[lw],l[lw]};
				}
				else
				{
					lw-=1,rw+=1;
					nt1={le[lw],l[lw]};
					nt2={ri[rw],r[rw]};
				}
			}
			else
			{
				if(te1.first>te2.first)
				{
					rw+=1;
					ans+=te2.first;
					nt1={te1.first-te2.first,te1.second};
					nt2={ri[rw],r[rw]};
				}
				else if(te2.first>te1.first)
				{
					ans+=te1.first;
					nt2={te2.first-te1.first,te2.second};
					lw-=1;
					nt1={le[lw],l[lw]};
				}
				else
				{
					lw-=1,rw+=1;
					ans+=te1.first;
					nt1={le[lw],l[lw]};
					nt2={ri[rw],r[rw]};
				}
			}
			if(rw>rj&&lw<1) break;
			te1=nt1;
			te2=nt2;
		}
		cout<<ans;
	}
	else
	{
		const ll mid=sum/2;
		ll t=mid,t1=mid;
		ll le[N]={0},ri[N]={0},li=0,rj=0,lq=0,rq=0;
		string l,r;
		bool flag;
		for(ll i=1;i<=n;++i)
		{
			if(t-a[i]>0||flag==1)
			{
				t-=a[i];
				if(!flag)
				{
					le[++li]=a[i];
					lq+=a[i];
					l[li]=c[i];
				}
				else
				{

					ri[++rj]=a[i];
					rq+=a[i];
					r[rj]=c[i];
				}
				
			}
			else if(flag==0)
			{
				flag=1;
				//a[i]-t;
				le[++li]=t1-lq;
				l[li]=c[i];
				ri[++rj]=a[i]-(t1-1-lq);
				r[rj]=c[i];
			}
			//cout<<"\n\n\n\n\n\n\n\n";
			//cout<<'\n'<<a[i]<<' '<<c[i]<<'\n';
			//cout<<"\n\n\n\n\n\n\n\n";
			//for(int i=1;i<=li;++i)
		//	{
			//	cout<<le[i]<<' '<<l[i]<<'\n';
			//}
			//cout<<'\n';
			//for(int i=1;i<=rj;++i)
			//{
			//	cout<<ri[i]<<' '<<r[i]<<'\n';
			//}
		}
		pair<ll,char>te1={le[li],l[li]},te2={ri[1],r[1]};
		ll lw=li,rw=1;
		while(1)
		{
			//cout<<'\n'<<ans;
			//cout<<"\n\n"<<te1.first<<' '<<te1.second<<"\n"<<te2.first<<' '<<te2.second;
			pair<ll ,char>nt1,nt2;
			if(te1.second==te2.second)
			{
				if(te1.first>te2.first)
				{
					nt1={te1.first-te2.first,te1.second};
					rw+=1;
					nt2={ri[rw],r[rw]};
				}
				else if(te2.first>te1.first)
				{
					nt2={te2.first-te1.first,te2.second};
					lw-=1;
					nt1={le[lw],l[lw]};
				}
				else
				{
					lw-=1,rw+=1;
					nt1={le[lw],l[lw]};
					nt2={ri[rw],r[rw]};
				}
			}
			else
			{
				if(te1.first>te2.first)
				{
					rw+=1;
					ans+=te2.first;
					nt1={te1.first-te2.first,te1.second};
					nt2={ri[rw],r[rw]};
				}
				else if(te2.first>te1.first)
				{
					ans+=te1.first;
					nt2={te2.first-te1.first,te2.second};
					lw-=1;
					nt1={le[lw],l[lw]};
				}
				else
				{
					lw-=1,rw+=1;
					ans+=te1.first;
					nt1={le[lw],l[lw]};
					nt2={ri[rw],r[rw]};
				}
			}
			if(rw>rj&&lw<1) break;
			te1=nt1;
			te2=nt2;
		}
		cout<<ans;
	}
	return 0;
}
