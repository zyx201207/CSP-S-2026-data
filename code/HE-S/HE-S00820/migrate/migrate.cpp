#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[5010];
struct book{
	int u,num;
};
book ans[5010];
bool vis[5010];
vector<int> arr[5010];
void dfs(int p,int use){
	if(use<ans[p].u){
		ans[p].num=0;
		ans[p].u=use;
	}
	if(use==ans[p].u){
		ans[p].num++;
	}
	for(int i=0;i<arr[p].size();i++){
		if(vis[arr[p][i]]==true) continue;
		vis[arr[p][i]]=true;
		dfs(arr[p][i],use+1);
		vis[arr[p][i]]=false;
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int times=1;times<=t;times++){
		cin>>n>>d;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			arr[i].clear();
			ans[i].u=INT_MAX;
			ans[i].num=0;
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					arr[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int p=1;p<=n;p++){
				ans[p].num=0;
				ans[p].u=INT_MAX;
			} 
			dfs(i,0);
			for(int j=1;j<=n;j++){
				if(ans[j].num==2 && i<=j){
//					cout<<ans[j].u<<endl;
//					cout<<i<<" "<<j<<endl;
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
}
