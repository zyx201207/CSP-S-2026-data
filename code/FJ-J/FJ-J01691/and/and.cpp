#include<bits/stdc++.h>
using namespace std;
const int MAXN=200000+10;
long long a[MAXN];
int n,k;
int m=0;
bool v[MAXN];
int yihuo(int s,int f)
{
	int qs=0;
	int p=1;
	int qf=0;
	while(s!=0)
	{
		qs+=s%2*p;
		s/=2;
		p*=10;	
	}
	p=1;
	while(f!=0)
	{
		qf+=f%2*p;
		f/=2;
		p*=10;	
	}
	string l=to_string(qs);
	string r=to_string(qf);
	int ma=max(l.size(),r.size());
	if(ma==l.size())
	{
		string strf="";
		for(int k=1;k<=l.size()-r.size();k++)
		{
			strf+="0";
		}
		strf+=r;
		r=strf;
	}
	else
	{
		string strs="";
		for(int k=1;k<=r.size()-l.size();k++)
		{
			strs+="0";
		}
		strs+=l;
		l=strs;
	}
	string ans=0;
	p=1;
	for(int j=0;j<l.size();j++)
	{
		if(l[j]=='0' || r[j]=='0')
		{
			ans+='0';
		}
		else
		{
			ans+='1';
		}
	}
	int abc=0;
	int cnt=0;
	for(int k=ans.size()-1;k>=0;k--)
	{
		if(ans[k]=='1')
		{
			cnt+=abc*1;
			abc++;
		}
		else
		{
			cnt+=0;
		}
	}
	return cnt;
}
void dfs(int x,int core)
{
	if(x==k)
	{
		m=max(m,core);
		return;
	}
	for(int i=x;i<=n;i++)
	{
		if(v[i]==false)
		{
			v[i]=true;
			dfs(x+1,yihuo(core,a[i]));
			v[i]=false;
		}
	}
	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<yihuo(3,15)<<endl;
	cout<<m;
	return 0;
}
