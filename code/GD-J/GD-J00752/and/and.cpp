#include<bits/stdc++.h>
using namespace std;
int a[1000];
int s[1000];
int n,m;
int maxn;
void check(){
	int l=0,c=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1&&c>0){
			l=l&s[i];
			c++;
			
		}
		if(c==0&&a[i]==1){
			l=s[i];
		}
		
	}
	maxn=max(maxn,l);
}
void dfs(int step,int last){
	if(step>m){
		check();
		return ;
	}
	for(int i=last+1;i<=n;i++){
		a[i]=1;
		dfs(step+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	dfs(1,0);
	cout<<maxn;
	return 0;
}
