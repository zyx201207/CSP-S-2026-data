#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int n,m;
int ans;
int a[N];
int d[N][N];
void dfs(int pos,int da,int sum){
	if(da>m) return;
	else if(pos==n+1&&da==m){
		ans=max(ans,sum);
		return;
	}
	else if(pos==n+1&&da<m) return;
	else if(d[pos][da]>=sum){
		return;
	} 
	else{
		d[pos][da]=sum;
		dfs(pos+1,da,sum);
		dfs(pos+1,da+1,sum&a[pos]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,pow(2,31)-1);
	cout<<ans<<endl;
	return 0;
}
