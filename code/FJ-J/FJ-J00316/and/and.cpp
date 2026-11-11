#include<bits/stdc++.h>
using namespace std;
const long long M=2e5+5;
long long ans=0;
	long long n,m,a[M],cho[M];
	int book[M];
void dfs(int step,long long num){
	if(step==m+1){
		long long ans1=cho[1];
		for(int i=2;i<step;i++){
			ans1|=cho[i];
		}
		ans=max(ans1,ans);
		return;
	}
	for(int i=num+1;i<=n;i++){	
	if(book[i]==0){
	book[i]=1;
	cho[step]=a[i];
	dfs(step+1,i);
	book[i]=0;
	}
}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
		dfs(0,1);
	cout<<ans;
	return 0;
}
