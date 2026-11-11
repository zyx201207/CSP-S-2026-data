#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int N,M;
int a[200010],ans;
void DFS(int x,int num,int pos){
	if(x==M){
		ans=max(ans,num);
		return ;
	}
	for(int i=pos+1;i<=N;i++){
		DFS(x+1,(num&a[i]),i);
	}
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	for(int i=1;i<=N;i++){
		DFS(1,a[i],i);
	}
	cout<<ans;
	return 0;
}
