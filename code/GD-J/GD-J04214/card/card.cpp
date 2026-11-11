#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e5+5,M=3e5+5;
int n,m;
int a[N],lst[M],ans[M];
bool vis[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) lst[j]=-1;
		vector<int> v;
		for(int j=i;j<=n;j++) v.push_back(a[j]);
		int len=v.size();
		for(int j=0;j<len;j++)
		{
			if(lst[v[j]]!=-1&&v[lst[v[j]]]==v[j])
			{
				for(int k=lst[v[j]];k<j;k++)
				{
					v[k]=-1;
				}		
			}
			lst[v[j]]=j;
		}
		for(int j:v)
		{
			if(j!=-1&&!vis[j])
			{
				vis[j]=1;
				++ans[j];
			}
		}
		for(int j:v)
		{
			if(j!=-1&&vis[j]) vis[j]=0;	
		}
	}
	for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//constexpr int N=5e5+5,M=3e5+5;
//int n,m,ct;
//int a[N],cnt[M],ans[M],lst[M];
//int val[M];
//pair<int,int> p[N];
//bool vis[N];
//int main()
//{
////	freopen("card.in","r",stdin);
////	freopen("card.out","w",stdout);
//	scanf("%d %d",&n,&m);
//	for(int i=1;i<=n;i++) 
//	{
//		scanf("%d",&a[i]);
//		if(lst[a[i]]) p[++ct]={lst[a[i]],i-1};
//		lst[a[i]]=i;
//	}
//	for(int i=n;i>=1;i--)
//	{
//		if(!ans[a[i]]) ans[a[i]]=i;
//	}
//	sort(p+1,p+1+ct);
//	p[ct+1].first=n+1;
//	cout<<ct<<endl;
//	for(int i=ct;i>=1;i--)
//	{
//		for(int j=p[i].first;j<p[i+1].first;j++) ++cnt[a[j]]; 
//		cout<<p[i].first<<" "<<p[i].second<<endl;
////		for(int j=1;j<=m;j++) cout<<cnt[j]<<" ";
////		cout<<"\n"; 
//		for(int j=p[i].first;j<=p[i].second;j++)
//		{
//			if(vis[j]) continue;
//			vis[j]=1;
//			++val[a[j]];
//		}
//		for(int j=1;j<=m;j++)
//		{
//			cout<<j<<" "<<val[j]<<" "<<cnt[j]<<"\n";
//			if(val[j]==cnt[j]&&cnt[j]!=0) --ans[j];
//		}
//		cout<<"\n";
//	}
//	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
//	return 0;
//} 

