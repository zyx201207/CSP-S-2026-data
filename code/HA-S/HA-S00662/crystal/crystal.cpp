#include<bits/stdc++.h>
using namespace std;
int a[500001];
bool a1[500001];
int dfs(int i1,int step,int ans,int i){
	if(step==0){
		return ans;
	}else{
		if(a[i]-a[i1-1]<=step&&i1-1>=1){
			ans++;
			dfs(i1-1,step-a[i]+a[i1-1],ans,i);
		}else{
			return ans;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=2;i<=n;i++){
		ans=max(dfs(i,m,1,i),ans);
	}
	cout<<ans;
	return 0;
} 
