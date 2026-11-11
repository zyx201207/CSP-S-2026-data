/*
and

开long long

50-60-?

*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],ans=0,cnt,t;
void dfs(int st,int cnt,int many){
	if(cnt<=ans){
		return ;
	}
	if(many==m){
		ans=cnt;
		return ;
	}
	if(st+m-many-1>n){
		return ;
	}
	for(int i=st;i<=n;i++){
		dfs(i,cnt&a[i],many+1);
	}
}
void goo(int nott){
	long long cnt=0;
	if(nott==1){
		cnt=a[2];
		for(int i=3;i<=n;i++){
			cnt=cnt&a[i];
			if(cnt<=ans){
				return ;
			}
		}
		ans=max(ans,cnt);
		return ;
	}
	cnt=a[1];
	for(int i=2;i<=n;i++){
		if(i!=nott){
			cnt=cnt&a[i];
		}
		if(cnt<=ans){
			return ;
		}
	}
	ans=max(ans,cnt);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){//6
		cout<<a[n];
		return 0;
	}
	if(m==n){//7
		for(int i=2;i<=n;i++){
			a[1]=a[1]&a[i];
		}
		cout<<a[1];
		return 0;
	}
	if(m==2){//8-10
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){//11,12
		for(int i=1;i<=n;i++){
			goo(i);
		}
		cout<<ans;
		return 0;
	}
	//DFS1-5
	if(n<=20){
		for(int i=n-m+1;i>=1;i--){
			dfs(i+1,a[i],1);
		}
		cout<<ans;
		return 0;
	}
	//从小往大选m个，保证结果为最小的,倒序，一但成功就输出
	for(int i=n-m+1;i>=1;i--){//枚举起点
		cnt=1;
		t=a[i];
		for(int j=i+1;j<=n && cnt<m;j++){
			if((t&a[j])==a[i]){
				cnt++;
			}
		}
		if(cnt==m){
			cout<<a[i];
			return 0;
		}
	}
	cout<<0;
	return 0;
}
