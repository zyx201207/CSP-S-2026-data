#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],k,b[200010],maxx;
bool f[200010];
bool fl,fg,fe;
long long fun(int k){
	long long t=b[1];
	for(int i=2;i<=k;i++){
		t&=b[i];
	}
	return t;
}
void dfs(int k){
	for(int i=1;i<=n;i++){
		if(!f[a[i]]){
			f[a[i]]=1;
			b[k]=a[i];
			if(k==m){
				maxx=max(fun(k),maxx);
			}
			else dfs(k+1);
			f[a[i]]=0;
		}
	}
}
bool check(long long x){
	long long p=30;
	while(p>=0){
		long long po=pow(2,p)-1;
		if(x==po)return 1;
		p--;
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4)fe=1;
		if(i-1!=a[i])fg=1;
		if(!check(a[i]))fl=1;
		if(i==1)k=a[i];
		else k=k&a[i];
	}
	sort(a+1,a+n+1);
	if(!fl||!fg||!fe||m==n-1){
		long long t=a[n];
		for(int i=n-1;i>=n-m+1;i--)t&=a[i];
		cout<<t;
		return 0;
	}
	if(m==1){
		cout<<a[n];
		return 0;
	}
	else if(m==n){
		cout<<k;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(a[i]&a[j],maxx);
			}
		}
		cout<<maxx;
		return 0;
	}
	else{
		dfs(1);
		cout<<maxx;
		return 0;
	}
	return 0;
}
