#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
vector<int>w[32];
int n,m,a[maxn],ans[maxn];
int len,cnt=0,tmp;
bool vis[maxn];
void calc()
{
	if(!tmp&&len)tmp=a[ans[1]];
	for(int j=1;j<=len;j++){
		vis[ans[j]]=0;
		tmp=tmp&a[ans[j]];
	}
}
void choose(int k,int x){
	if(len==x){
		calc();
		return;
	}
	len=1;
	for(int i=k;i>=0;i--){
		if(w[i].size()<x)continue;
		for(int j=0;j<w[i].size();j++)
		{
			if(!vis[w[i][j]])continue;
			ans[++len]=w[i][j];
		}
		if(len<x){
			calc();
			choose(i-1,x-len);
			return;
		}
	}
	calc();
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=0;j<=31;j++){
			if(a[i]&(1<<j))w[j].push_back(i);
		}
	}
	for(int i=31;i>=0;i--){
		if(w[i].size()<m)continue;
		for(int j=0;j<w[i].size();j++){
			ans[++len]=w[i][j];vis[ans[len]]=1;
		}
		choose(i-1,m);
		cout<<tmp;
		return 0;
	}
	if(!len){
		cout<<0;
		return 0;
	}
}
