#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,m;
int a[N];
int ans[N];
struct node{
	bool flag;
	int id;
}vis[N];
vector<int>v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[N];
	}
	for(int k = 1;k <= n;k++){
		for(int i = i;i <= n;i++){
			if(!vis[a[i]].flag){
				vis[a[i]].flag = 1;
				vis[a[i]].id = i;
				v.push_back(a[i]);
			}
			else{
				for(int j = vis[a[i]].id;j <= i;j++){
					v.pop_back();
				}
				vis[a[i]].flag = 0;
			}
		}
		for(int i : v){
			ans[i]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
