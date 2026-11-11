#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,a[N],ans,vis[N];
vector<int>v[N];
void dfs(long long step,long long x,long long id){
	v[id].push_back(step);
	for(int i=id+1;i<=n;i++){
		if(a[i]-a[id]<=d)dfs(step+1,a[i],i);
		else break;
	}
}
long long read(){
	long long x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		for(int i=1;i<=n;i++)v[i].erase(v[i].begin(),v[i].end());
		n=read();
		d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		dfs(0,1,1);
		ans=0;
		for(int i=1;i<=n;i++){
			if(v[i].empty())continue;
			sort(v[i].begin(),v[i].end());
			//for(int j=0;j<v[i].size();j++)cout<<v[i][j]<<' ';
			//cout<<endl;
			
			if(v[i][0]==v[i][1]&&v[i][0]!=v[i][2]&&v[i][0])ans++;
		}
		cout<<ans<<'\n';
		
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
