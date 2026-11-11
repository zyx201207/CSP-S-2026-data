#include<bits/stdc++.h>
using namespace std;
int n,m,ma,mi;
struct t3{
	int n;
	string s;
};
t3 a[200005];
map<int,int>mp;
string ans;
bool st=0;
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int u;
		cin>>a[i].n;
		if(a[i].n>ma)
		{
			ma=a[i].n;
			mi=i;
		}
		u=a[i].n;
		while(u)
		{
			char c='0'+(u%2);
			a[i].s=c+a[i].s;
			u/=2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		while(a[i].s.size()<a[mi].s.size())
		{
			a[i].s='0'+a[i].s;
		}
	}
	int u=a[mi].s.size();
	for(int i=0;i<u;i++)
	{
		int sum=0;
		ans+="0";
		for(int j=1;j<=n;j++)
		{
			if(mp[j])continue;
			if(a[j].s[i]=='1')sum++;
			else if(st==1)mp[j]=1;
		}
		if(sum>=m)
		{
			ans[i]='1';
			if(!st)
			{
				st=1;
				for(int j=1;j<=n;j++)
				{
					if(a[j].s[i]=='0')mp[j]=1;
				}
			}
		}
	}
	int ans2=0;
	for(int i=ans.size()-1,j=1;i>=0;i--,j*=2)
	{
		if(ans[i]=='1')ans2+=j;
	}
	cout<<ans2;
	return 0;
}
