#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;long long INF=(1<<31)-1;
int n,m;
long long a[N],b[N];
long long ans=0;
void dfs(int d,int t,long long sum){
	if(d>m){
		//for(int i=2;i<=m+1;i++) cout<<b[i]<<" ";
		//cout<<endl;
		//cout<<"sum="<<sum<<endl;
		ans=max(sum,ans);
		return;
	}
	for(int i=t+1;i<=n;i++){
		dfs(d+1,i,sum&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//cout<<INF<<endl;
	dfs(1,0,INF);
	cout<<ans<<endl;
	return 0;
}