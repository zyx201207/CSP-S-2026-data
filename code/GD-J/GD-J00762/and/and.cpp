#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans;
bool bbb=1,b4=1,B=1;
void dfs(int x,int y,int z) {
	if(y==m||x>n) {
		if(y!=m) return ;
		ans=max(ans,z);
	}
	dfs(x+1,y,z);
	dfs(x+1,y+1,z&=a[x]);
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);    
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		int x=log2(a[i]);
		if((1<<(x+1))-1!=a[i]) bbb==0;
		if(a[i]>3) b4=0;
		if(a[i]!=i-1) B=0;
	}
	sort(a+1,a+n+1);
	if(m==1) {//1
		cout<<a[n];
		return 0;
	} 
	if(bbb==1) {   //2
		cout<<a[n-m+1];
		return 0;
	}
	if(m==n) {//3
		ans=a[1];
		for(int i=2;i<=n;i++) {
			ans&=a[i];
		}  
		cout<<ans;
		return 0;
	}
	if(b4==1) {   //4
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--) {
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(B==1) {//5
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--) {
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2) {//6
		cout<<(a[n]&a[n-1]);
		return 0;
	}
	ans=0;
	if(n<=20) { //7
		dfs(1,0,(1<<30)-1);
		cout<<ans;
		return 0;
	}
	//8
	ans=a[n];
	for(int i=n-1;i>=n-m+1;i--) {
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}

