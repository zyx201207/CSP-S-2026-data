#include<bits/stdc++.h>
using namespace std;
int n;
struct sz{
	int l;
	string s;
};
string s1;
int ans,sum,lz;
bool vis[1000005];
sz str[200005];
void dfs(int i)
{
	for(int j=0;j<=lz;j++)
	{	
		if(j>=lz+1-j)
		{
			ans=min(ans,sum);
			sum=0;
			return;
		}
		if(vis[j]==0)
		{
			vis[j]=1;
			if(s1[j]!=s1[lz-j+1])
			{
				s1[lz-j+1]=s1[j];
				vis[lz-j+1]=1;
				sum++;
				dfs(j);
				vis[j]=0;
				vis[lz-j+1]=0;
			}
		}
	}
	ans=min(ans,sum);
	sum=0;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)
	{
		cin>>str[i].l>>str[i].s;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<str[i].l;j++)
		{
			s1=s1+str[i].s;
		}
	}
	for(int i=0;i<n;i++)
	{
		lz+=str[i].l;
	}
	ans=lz;
	dfs(0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


