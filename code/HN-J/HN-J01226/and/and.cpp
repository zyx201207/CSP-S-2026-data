#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100],ans=-1;
void dfs(long long t,long long size1,long long x){
	cout<<t<<size1<<"  "<<x<<endl;
	if(size1==m){
		cout<<"amx"<<endl;
		ans=max(ans,t);
		cout<<"ooo"<<ans<<endl;
		return ;
	}
	if(x>n) return;
	//cout<<"rrrr"<<ans<<endl;
	if(t==-1){
		dfs(a[x],size1+1,x+1);
		dfs(-1,size1,x++);
		return ;
	}
	long long b=t&a[x];
	//cout<<"bbb"<<b<<endl;
	
	dfs(b,size1+1,x+1);
	dfs(t,size1,x++);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	//dfs(-1,0,1);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans; 
	return 0;
} 
