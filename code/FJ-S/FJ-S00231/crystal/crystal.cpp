#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m;
int a[N];
int vis[N];
int ans=-1;
void dfs(int t){
	int num=-1;
	for(int i=1;i<=n;i++)vis[a[i]]=0; 
    for(int i=1;i<=n;i++)vis[a[i]]++;
	for(int i=1;i<=n;i++)num=max(num,vis[a[i]]);
    ans=max(ans,num);
    if(t==0)return;
    t--;
	for(int j=1;j<=n;j++){
		a[j]++;
		dfs(t);
		a[j]--;
	}	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	dfs(m);
	cout<<ans;
	return 0;
} 
/*5 8
 -3 -1 2 2 7*/
//2026年10月31日于滨海 
