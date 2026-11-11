#include<bits/stdc++.h>
using namespace std;
int n,m,Max,sum,ANS;
int v[200005];
bool f[2000005];
void dfs(int M,int ans){
	if(M==0){
		ANS=max(ANS,ans);
		return;
	}
	for(int i=1;i<=n-M+1;i++){
		if(!f[i]){
			f[i]=1;
			dfs(M-1,ans&v[i]);
			f[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	sum=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		sum&=v[i];
		Max=max(Max,v[i]);
	}
	if(m==1){
		cout<<Max;
	}
	if(m==n){
		cout<<sum;
	}
	dfs(m,INT_MAX);
	cout<<ANS;
	return 0;
}
