//GZ-J00456
//贵阳市白云区华师一学校 
//廖博亚 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=2e5+5;
const int N2=5e6+3;
struct node
{
	ll num;
	char c;
}s[N],ns[N];
char ch[N2];
signed main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin>>t;
	ll Max=0;
	ll flag=0;
	for(ll i=1;i<=t;i++)
	{
		ll n;
		char m;
		cin>>n>>m;
		flag+=n;
		s[i].num=n;
		s[i].c=m;
		Max+=s[i].num;
	} 
	if(flag<=5e6)
	{
		int sl=0;
		for(ll i=1;i<=t;i++)
		{
			while(s[i].num!=0)
			{
				ch[++sl]=s[i].c;
				s[i].num--;
			}
		}
		ll res=0;
		for(int i=1;i<=sl/2;i++)
		{
			if(ch[i]!=ch[sl-i+1]) res++;
			
		} 
		cout<<res<<endl;
		return 0;
	}
	s[0].c=s[1].c;
	s[0].num=0;
	s[t+1].c=' ';
	s[t+1].num=0;
	ll res=0;
	ll nt=0;
	for(ll i=1;i<=t+1;i++)
	{
		if(s[i].c!=s[i-1].c)
		{
			++nt;
			ns[nt].num=res;
			ns[nt].c=s[i-1].c;
			res=0;
		}
		res+=s[i].num;
	}
	if(Max%2==1)
	{
		ll temp=Max/2+1;
		ll Now=0;
		for(ll i=1;i<=t;i++)
		{
			Now+=ns[i].num;
			if(Now>=temp)
			{
				ns[i].num-=1;
				break;
			}
		}
	}
	ll k=0;
	res=0;
	for(ll i=1;i<=nt;i++)
	{
	//	cout<<ns[i].num<<" "<<ns[nt-i-py+1].num<<endl;
		if(ns[i].c!=ns[nt-i+1].c)
		{
			res+=min(ns[i].num,ns[nt-i+1].num+k);
			ns[nt-i+1].c=ns[i].c;
			//cout<<1<<endl;
		}
		else if(ns[i].num!=ns[nt-i+1].num+k)
		{
			res+=abs(ns[i].num-(ns[nt-i+1].num+k));
			k+=(ns[nt-i+1].num+k)-ns[i].num; 
			ns[nt-i+1].num=ns[i].num;
			
		//	cout<<1<<endl;
		 } 
		// cout<<res<<" "<<k<<endl;
	}
	cout<<res<<'\n';
}
