#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool flag[200005];
long long ans=0;
void dfs(int r,long long sum){
	if(r==0){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i])flag[i]=true;
		else continue;
		if(sum==0){
			sum+=a[i];
			dfs(r-1,sum);
			sum-=a[i];
		}else{
			int summ=sum&a[i];
			dfs(r-1,summ);
		}
		flag[i]=false;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n,greater<int>());
		cout<<a[1];
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(m,0);
		cout<<ans;
	}
	return 0;
} 
