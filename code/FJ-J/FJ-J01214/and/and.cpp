#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n,m;
long long ans;
void dfs(int gs,int i,long long mq){
//	cout<<"\n---\nIN DFS\n";
	if(gs>m){
//		printf("\n答案:%lld\n===\n",mq);
		ans=max(mq,ans);
		return;
	}
	if(i>=n)return;
	//选
//	printf("\tY %d %d %lld\n",gs+1,i+1,(mq==0)?a[i]:(mq&a[i]));
	if(mq==0)dfs(gs+1,i+1,a[i]);
	dfs(gs+1,i+1,mq&a[i]);
	//不选
//	printf("\tN %d %d %lld\n",gs,i+1,mq);
	dfs(gs,i+1,mq); 
}
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n,cmp);
		cout<<a[0];
		return 0;	
	}
	if(n==m){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0,0);

//	ans=a[0];
//	cout<<"\n\n\n===\n\n\n===\n\n\n===\n\n\n";
//	for(int i=0;i<n;i++)cout<<a[i]<<' ';
//	for(int i=1;i<m;i++){
//		ans=andbit(ans,a[i]);
//	}
	cout<<ans;
	return 0;
}

