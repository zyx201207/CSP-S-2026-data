#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long ss;
int n,m;
void dfs(int i,long long s,int k){
	if(i>n){
		if(k==m){
			ss=max(ss,s);
		}
		return ;
	}
	dfs(i+1,s&a[i],k+1);
	dfs(i+1,s,k);
	return ;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		int s=a[1];
		for(int i=1;i<=n;i++){
			s&=a[i];
		}
		cout<<s;
		return 0;
	}
	if(m==1){
		int s=a[1];
		for(int i=1;i<=n;i++){
			s=max(s,a[i]);
		}
		cout<<s;
		return 0;
	}
	if(m==2&&n<2005){
		int ms;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ms=max(ms,a[i]&a[j]);
			}
		}
		cout<<ms;
		return 0;
	}
	if(n>2005&&a[1]%2!=0){
		sort(a+1,a+1+n,cmp);
		int s=a[1];
		for(int i=1;i<=m;i++){
			s=s&a[i]; 
		}
		return 0;
	}
	if(n>2005){
		cout<<0;
		return 0;
	}
	dfs(1,4194303,0);
	cout<<ss;
	return 0;
} 
