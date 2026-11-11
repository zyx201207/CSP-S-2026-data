#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
bool b[N];
int ans=-1;
int n,m;
void dfs(int p,int d){
	if(p==n+1){
		if(m==d){
			int k;
			bool y=true;
			for(int i=1;i<=n;i++){
				if(b[i]&&y){
					y=false;
					k=a[i];
				}
				else if(b[i])k=k&a[i];
			}
			ans=max(ans,k);
		}
		return;
	}
	if(n-p+1<m-d)return ;
	b[p]=true;
	dfs(p+1,d+1);
	b[p]=false;
	dfs(p+1,d);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
}
