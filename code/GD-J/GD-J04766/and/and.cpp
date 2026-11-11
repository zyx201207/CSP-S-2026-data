#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+5;
int n,k,a[N],b[N],xb,sum,ans,maxx,c[3097152],cnt;
string s[N],t[N];
bool cmp(string a,string b)
{
	if(a.size()!=b.size())
	{
		return a.size()>b.size();
	}
	else
	{
		return a>b;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=a[i];
		xb=0;
		while(1)
		{
			if(x==0) break;
			b[++xb]=x%2;
			x=x/2;
		}
		for(int j=xb;j>=1;j--)
		{
			s[i]=s[i]+char(b[j]+48);
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<s[i].size();j++)
		{
			if(s[i][j]=='1')
			c[(long long)(1<<(s[i].size()-j-1))]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		bool pd=0;
		for(int j=0;j<s[i].size();j++)
		{
			if(s[i][j]=='1') 
			{
				if(c[(long long)(1<<(s[i].size()-j-1))]>=2)
				{
					pd=1;
					break;
				}
			}
			else
			{
				pd=0;
			}
		}
		if(pd==1)
		{
			t[++cnt]=s[i];
		}
	}
	sort(t+1,t+cnt+1,cmp);
	for(int i=1;i<=min(cnt,k);i++)
	{
		sum=0;
		for(int j=0;j<t[i].size();j++)
		{
//			cout<<s[i][j]<<" "<<s[i].size()<<"\n";
			sum+=(long long)(1<<(t[i].size()-j-1))*(t[i][j]-'0');
		}
		if(i==1)
			ans=sum;
		else
		{
			ans=(ans&sum);
		}
	}
	cout<<ans;
	return 0;
} 
