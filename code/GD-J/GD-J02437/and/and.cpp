#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int da=-1,shu=0;
int daa=-1;
int v[200005];
void dfs(int x,int t){
	if(t>=m){
		daa=max(x,daa);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			dfs(x & a[i],t+1);
			v[i]=0;
		}
	}
} 
long long aaa(int x){
	int x1=1;
	for(int i=1;i<=x;i++) x1*=2;
	return x1-1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int f=1;
	int a1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) a1=a[i];
		if(da==a[i]) shu++;
		if(da<a[i]) da=a[i],shu=1;
		a1=a1 & a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) if(f==1) if(a[i]!=aaa(i)) f=0;
	if(f==1){
		cout<<a[n-m+1];
		return 0;
	}
	if(n==m){
		cout<<a1;
		return 0;
	}
	else if(shu>=m){
		cout<<da;
		return 0;
	}
	else {
		for(int i=1;i<=n;i++) v[i]=0;
		for(int i=1;i<=n;i++) {
			v[i]=1;
			dfs(a[i],1);
			v[i]=0;
		}
	}
	cout<<daa;
	return 0;
} 
