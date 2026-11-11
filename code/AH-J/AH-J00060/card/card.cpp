#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],ans[N],nxt[N],ind[N];
int vis[N];
struct node{
	int len,a;
};
vector<node> nw;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	bool flag=1;
	int c=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
			flag=0;
		if(a[i]!=a[i-1])
			c++;
	}
	if(m==1){//?pts
		cout<<n;
		return 0;
	}
	if(n>5000&&m==2){//test13 14 8pts
		ans[a[n]]=n;
		if(a[1]==a[n]){
			for(int i=1,j;i<=n&&j<=n;){
				while(a[i]==a[i+1]&&i<n)i++;
				j=i+1;
				while(a[j]==a[j+1]&&j<n)j++;
				if(j>n)continue;
				ans[3-a[n]]+=j-i,i=j+1;
			}
		}
		else{
			int i=2;
			while(a[i]==a[i-1])i++;
			ans[3-a[n]]+=i-1; 
			for(int j;i<=n&&j<=n;){
				while(a[i]==a[i+1]&&i<n)i++;
				j=i+1;
				while(a[j]==a[j+1]&&j<n)j++;
				if(j>n)continue;
				ans[3-a[n]]+=j-i,i=j+1;
			}
		}
		cout<<ans[1]<<" "<<ans[2];
		return 0;
	}
	if(flag){//test20 4pts
		for(int i=1;i<=n;i++)
			ans[a[i]]=i;
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<" ";
		return 0;
	}
	if(n>5000&&c<=5500){//test15-17 12pts
		for(int i=1;i<=n;i++){
			int tmp=i;
			while(i<n&&a[i]==a[i+1])i++;
			nw.push_back({i-tmp+1,a[i]});
		}
		n=nw.size();
		for(int i=0;i<n;i++){
			nxt[ind[nw[i].a]]=i;
			ind[nw[i].a]=i;
		}
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				vis[nw[j].a]=nw[i].len;
				while(nxt[j])
					j=nxt[j];
			}
			for(int i=1;i<=m;i++)
				ans[i]+=vis[i],vis[i]=0;
		}
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<" ";
		return 0;
	}
	//test1-12 48pts
	for(int i=1;i<=n;i++)
	{
		nxt[ind[a[i]]]=i;
		ind[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			vis[a[j]]=1;
			while(nxt[j])
				j=nxt[j];
		}
		for(int i=1;i<=m;i++)
			if(vis[i])
				ans[i]++,vis[i]=0;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
} 
