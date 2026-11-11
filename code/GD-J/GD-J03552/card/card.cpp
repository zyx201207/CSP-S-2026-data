#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N];
int ans[N];
bool vis[N];
int lst[N];
void solve(int s){
	memset(vis,false,sizeof(vis));
	memset(lst,0,sizeof(lst));
	for(int i=s;i<=n;i++){
		int now=a[i];
		if(lst[now]==0||vis[lst[now]]){
			lst[now]=i;
		}
		else{
			for(int j=lst[now];j<i;j++){
				vis[j]=true;
			}
			lst[now]=i;
		}
	}
	for(int i=s;i<=n;i++){
		if(!vis[i]){
			ans[a[i]]++;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i<m)	cout<<' ';
		else cout<<'\n';
	}
	return 0;
}
/*
4 3
1 2 1 3
3 1 4

10 3
3 1 2 1 3 2 3 1 2 1
10 3 3

fc card4.txt ans4.txt
*/
