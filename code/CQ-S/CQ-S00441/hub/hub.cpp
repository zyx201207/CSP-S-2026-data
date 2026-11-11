#include<bits/stdc++.h>//没有建造的城市到任意一个建造的城市的最小值  的最大值 的最小值 
using namespace std;
int c,t;
int n,k;
vector<int>a[4005];
int s[4005][4005],ss[4005];
bool vis[4005];
int dfs(int bs,int id){
	if(bs==k+1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			int ans1=n;
			for(int j=1;j<=n;j++){
				if(!vis[j])continue;
				ans1=min(ans1,s[i][j]);//最小值 
			}
			ans=max(ans,ans1);//最大值 
		}
		return ans;
	}
	int ans=n;
	for(int i=id;i+k-bs<=n;i++){
		vis[i]=1;
		ans=min(ans,dfs(bs+1,i+1));//最小值 
		vis[i]=0;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			a[i].clear();
			for(int j=1;j<=n;j++)s[i][j]=0;
			ss[i]=0;
		}
		for(int i=1;i<n;i++){
			int ss,tt;
			cin>>ss>>tt;
			a[ss].push_back(tt);
			a[tt].push_back(ss);
		}//建图
		for(int i=1;i<=n;i++){
			queue<int>b;
			b.push(i);
			while(!b.empty()){
				int c=b.front();
				b.pop();
				if(ss[i] == n-1)break;
				for(auto x:a[c]){
					if(s[x][i]==0&&x!=i){
						s[x][i]=s[i][x]=s[i][c]+1;
						ss[i]++;
						ss[x]++;
						b.push(x);
					}
					else{
						b.push(x); 
					}
				}
			}
		}
		cout<<dfs(1,1)<<endl;
	}
	return 0;
}
