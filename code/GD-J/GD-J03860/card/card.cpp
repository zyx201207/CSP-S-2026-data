#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
long long ans[300005];
void csh(long long x){
	for(int i=x;i<=m;i++){
		b[i]=0;
	}
	return ;
}
void dfs(long long k,long long now,long long x){
	if(now>n){
		for(int i=1;i<=n;i++){
			ans[b[i]]++;
			//if(b[i]>0)cout<<b[i]<<" ";
		}
		//cout<<endl;
		return;
	}
	for(int i=0;i<now;i++){
		if(b[i]==a[now]){
			x=i;
			break;
		}
	}
	csh(x);
	b[x]=a[now];
	dfs(k,now+1,x+1);
}
int main(){
	freopen("card.in","r","stdin");
	freopen("card.out","w","stdout");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		csh(0);
		dfs(i,i,1);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
/*
*/
