#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
long long maxx;
long long path[30];
bool used[30];
void dfs(int now){
	if(now==m+1){
		long long t=path[1];
		for(int i=2;i<=m;i++){
			t=t&path[i];
//			cout<<path[i]<<' ';
//			cout<<maxx<<' ';
		}
//		cout<<endl;
		maxx=max(t,maxx);
		
		return;
	}
	for(int i=1;i<=n;i++){
		if(used[i]==0){
			used[i]=1;
			path[now]=a[i];
			dfs(now+1);
			used[i]=0;
			path[now]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		//ษ๎หั 
		dfs(1);
		cout<<maxx<<'\n';
		return 0;
	}else if(n<=2000){
		if(m==2){
			dfs(1);
			cout<<maxx<<'\n';
			return 0;
		}else if(m==n){
			long long t=a[1];
			for(int i=2;i<=n;i++){
				t=t&a[i];
			}
			cout<<t<<'\n';
			return 0;
		}else if(m==1){
			for(int i=1;i<=n;i++){
				maxx=max(maxx,a[i]);
			}
			cout<<maxx<<endl;
			return 0;
		}
	}else{
		if(m==n){
			long long t=a[1];
			for(int i=2;i<=n;i++){
				t=t&a[i];
			}
			cout<<t<<'\n';
			return 0;
		}else if(m==1){
			for(int i=1;i<=n;i++){
				maxx=max(maxx,a[i]);
			}
			cout<<maxx<<endl;
			return 0;
		}else{
			sort(a+1,a+1+n,greater<int>());
			cout<<a[m]<<'\n';
		}
	}
}
