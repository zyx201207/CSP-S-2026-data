#include<bits/stdc++.h>
using namespace std;
const int N=500005;
const int M=300005;
int n,m;
int a[N];
int cnt[M];
int vis[N];
vector<int>v; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		v.clear();
		memset(vis,0,sizeof(vis));
		for (int j=i;j<=n;j++){
			if (vis[a[j]]!=0){
 			   while (vis[a[j]]!=0 && !v.empty()){
 	                 if (v[(int)v.size()-1]==a[j]){
 	                 	vis[a[j]]--; 
		       		 }
		       		 v.pop_back();
				 }
				 v.push_back(a[j]);
			}else if (vis[a[j]]==0){
				  vis[a[j]]++;
                  v.push_back(a[j]);
	        }
		}
		for (int j=0;j<(int)v.size();j++){
			cnt[v[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
