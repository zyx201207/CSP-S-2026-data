#include<bits/stdc++.h> 
using namespace std;
int a[600001],op1=1,op2=1,f[600001];
int maxx=INT_MAX,book[500001],m,ans,n;
void dfs(int d){
	if(d==m+1){
		int x=f[1];
		for(int i=2;i<=m;i++)
			x=x&f[i];
		ans=max(x,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			f[d]=a[i];
			book[i]=1;
			dfs(d+1);
			book[i]=0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//cout<<a[i];
		int er=a[i];
		while(er){
			if(er%2==0){
				op1=0;
				break;	
			}
			er/=2;
		}
		if(a[i]!=i-1)	op2=0;
	}
	if(op1==1){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	else if(op2==1){
		ans=a[n];
		for(int i=n,j=1;j<=m;j++,i--){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}/*
6 3
31 3 1 15 7 63


49064
*/