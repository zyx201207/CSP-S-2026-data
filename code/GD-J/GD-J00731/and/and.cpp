#include<bits/stdc++.h>
using namespace std;
int a[200002];
int n,ans=0,m;
bool cmp(int a,int b){
	int p1,p2;
	for(int i=1;i<=30;i++){
		if(pow(2,30)>a){
			p1=i;
		}
	}
	for(int i=1;i<=30;i++){
		if(pow(2,30)>b){
			p2=i;
		}
	}
	int c1=pow(2,p1)-a,c2=pow(2,p2)-b;
	if(c1!=c2){
		return c1<c2;
	}
	return a>b;
}
bool vis[200002];
void dfs(int step,int sum){
	if(step>m){
		if(sum>ans){
			ans=sum;
		}
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(step+1,sum&a[i]);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1){//t6
		cout<<a[n-1];
		return 0;
	}
	if(m==n){//t7
		int ans=a[0];
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){//t8~10
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(a[n-1]<4){//t16,17
		int ans=0xF;
		for(int i=n;n-i+1>=m;i--){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(n<=20){//t1~5
		dfs(0,0xFFFFFFFF);
		cout<<ans;
		return 0;
	}
	sort(a,a+n,cmp);
	int ans=0;
	for(int i=0;i<m;i++){
		cout<<a[i]<<" ";
	}
	cout<<ans;
	return 0;
} 

