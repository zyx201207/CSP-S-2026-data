//中华人民共和国万岁，世界人民大团结万岁！ 
#include<bits/stdc++.h>
using namespace std;

int n,m,a[200010],ans;
void dfs(int i,int b,int sum){
	if(b==m){
		ans=max(ans,sum);
		return ;
	}
	if(i>=n) return ;
	dfs(i+1,b,sum);
	if(sum==0) sum=a[i+1];
	else sum=sum & a[i+1];
	dfs(i+1,b+1,sum);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<n-i;j++){
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
		}
		if(ans==0) ans=a[n+1-i];
		else ans=ans&a[n+1-i];
	}
	
	cout<<ans;
	return 0;
} 


