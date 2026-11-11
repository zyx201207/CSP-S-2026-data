#include<bits/stdc++.h>
using namespace std;
int n,m,ans=INT_MIN;
int a[200010];
bool book[200010];
void dfs(int step,int start,int sum){
	if(step==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=start;i<n;i++){
		if(book[i]==1) continue;
		book[i]=1;
		dfs(step+1,i+1,sum&a[i]);
		book[i]=0;
	}
}
int cmp(int a,int b){
	while(a&&b){
		if(a%2==1&&b%2==0) return 1>0;
		if(a%2==0&&b%2==0) return 0>1;
		a/=2,b/=2;
	}
	return a<b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	/*for(int i=0;i<n-m+1;i++){
		book[i]=1;
		dfs(1,i+1,a[i]);
		book[i]=0;
	}
	cout<<ans;*/
	ans=a[0];
	for(int i=1;i<m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
