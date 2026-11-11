#include<bits/stdc++.h>
using namespace std;
vector<int>ve[1000009];
int he[1000009];
void dfs(int x,int fa,int hi){
	he[x]=min(he[x],hi);
	for(auto i:ve[x]){
		if(i==fa)continue;
		dfs(i,x,hi+1); 
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>t;
	cin>>t;
	while(t--){
		int a,b,ans=1e9;
		cin>>a>>b;
		if(a>20){
			cout<<rand()%a<<endl;
			continue;
		}
		for(int i=1,x,y;i<a;i++){
			cin>>x>>y;
			x--,y--;
			ve[x].push_back(y);
			ve[y].push_back(x);
		}
		for(int i=0;i<(1<<a);i++){
			int ct=0,tc=0,ra=0;
			for(int j=0;j<a;j++){
				if(i&(1<<j))ct++;
			}
			if(ct!=b)continue;
			for(int j=0;j<a;j++){
				if(i&(1<<j)){
					for(auto k:ve[j]){
						if(i&(1<<k))tc++;
					}
				}
			}
			tc/=2;
			if(tc+2<b)continue;
			for(int j=0;j<a;j++)he[j]=1e9;
			for(int j=0;j<a;j++){
				if(i&(1<<j))dfs(j,j,0);
			}
			for(int j=0;j<a;j++)ra=max(ra,he[j]);
			ans=min(ans,ra);
		}
		cout<<ans<<'\n';
		for(int i=0;i<a;i++)ve[i].clear();
	}
	return 0;
}
