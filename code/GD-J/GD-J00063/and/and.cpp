#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N][35]={},b[N],vis[N]={};
long long s=LLONG_MIN;
void p(long long x,int y){
	int i=0;
	while (x!=0){
		int k=x%2;
		a[y][i]+=k;
		x/=2;
		i+=1; 
	}
	return ;
}
void dfs(int x,int t){
	vis[x]=1;
	b[t]=x;
	if (t==m){
		long long ans=0;
		for (int i=0;i<=30;i+=1){
			int f=1;
			for (int j=1;j<=m;j+=1){
				if (a[b[j]][i]==0){
					f=0;
					break;
				}
			}
			if (f){
				ans+=pow(2,i); 
			}
		}
		if (ans>s){
			s=ans;
		}
	}
	else {
		for (int i=1;i<=n;i+=1){
			if (!vis[i]){
				dfs(i,t+1);
			}
		} 		
	}
	vis[x]=0;
	return ;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i+=1){
		long long k;
		cin>>k;
		p(k,i);
	}
	for (int i=1;i<=n;i+=1){
		dfs(i,1);
	}
	cout<<s;
	return 0;
}
