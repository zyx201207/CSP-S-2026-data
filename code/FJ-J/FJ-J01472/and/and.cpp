#include<bits/stdc++.h>
using namespace std;
long long n,nn=INT_MAX,m,mm=INT_MIN,l,p=0;
long long a[1000005];
int dfs(int t,long long o){
	if(t==m){
		mm=max(mm,o);
		return 0;
	}
	dfs(t+1,o&a[t]);
	if(o==0){
		o=a[t];
		dfs(t+1,o);
	}
	dfs(t+1,o);
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
     cin>>n>>m;
    for(int i=1;i<=n;i++){
     	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int u=a[i]+1;
		while(u>=2){
			if(u%2==1)p=1;
			u/=2;
		}
	}
	if(n==m){
		int x=a[1];
		for(int i=2;i<=n;i++){
			x&=a[i];
		}
		cout<<x;
	} 
	else if(m==1){
		for(int i=1;i<=n;i++){
			mm=max(mm,a[i]);
		}
		cout<<mm;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mm=max(mm,a[i]&a[j]);
			}
		}
		cout<<mm;
	}
	else if(m==n-1){
		int x=0;
		for(int i=1;i<=n;i++){
			if(a[i]<nn){
				nn=a[i];
				l=i;
			}
		}
		if(l!=1){
			x=a[1];
		}
		else {
			x=a[2];
		}
		for(int i=1;i<=n;i++){
			if(i!=l)x&=a[i];
		}
		cout<<x;
	}
	else if(p==0) {
		sort(a+1,a+n+1);
		cout<<a[m];
	}
	else {
		dfs(1,0);
		cout<<mm;
	}
	return 0;
}
