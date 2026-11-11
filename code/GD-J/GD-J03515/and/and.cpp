#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans=0;
bool f[200005];
int n,m;
void dfs(int num,int front,long long sum){
	if(num==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=front;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			long long b=sum&a[i];
			if(sum==0){
				b=a[i];
			} 
			dfs(num+1,i+1,b);
			f[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	dfs(0,1,0);
	cout<<ans;
	return 0;
}
