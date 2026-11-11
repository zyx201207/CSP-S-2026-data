#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200010],f[20];
int dfs(int step,int k){
	int cnt=-1;
	if(step==m) return k;
	for(f[step]=f[step-1]+1;f[step]<=n;f[step]++){
		cnt=max(dfs(step+1,f[step]&k),cnt);
	}
	return cnt;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	//ysjfNB
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int cnt=-1;
		for(int i=1;i<=n;i++){
			cnt=max(cnt,a[i]);
		}
		cout<<cnt;
		return 0;
	}
	if(m==n){
		int cnt=1048575;
		for(int i=1;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	
	if(m==2){
		int cnt=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=max(cnt,a[i]&a[j]);
			}
		}
		cout<<cnt;
		return 0;
	} 
	bool b=1;
	for(int i=1;i<=n;i++){
		bool b1=0;
		for(int j=1;j<=20;j++){
			if(pow(2,j)-1==a[i]) b1=1;
		}
		b=(b&&b1);
	} 
	if(b){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	else{
		cout<<dfs(1,1048575);
	}
	return 0;
}
