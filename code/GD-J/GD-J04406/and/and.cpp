#include <bits/stdc++.h>
using namespace std;
string hq="";
int n,m;
int sum=INT_MIN;
long long a[200000+10];
bool vis[200000+10];
void dfs(int x,int cnt,int idx){
	if(cnt==m){
		sum=max(sum,idx);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			int o=idx&a[i];
			dfs(i,cnt+1,o);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(i,1,a[i]);
	}
	cout<<sum;

}
