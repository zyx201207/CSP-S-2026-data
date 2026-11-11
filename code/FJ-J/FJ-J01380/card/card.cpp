#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],ans[M]={0};
bool vis[M]={0};
stack<int> x;
void start(int i){
	for(;i<=n;i++){
		if(!vis[a[i]]){
			x.push(a[i]);
			vis[a[i]]=1;
		}
		else{
			while(x.top()!=a[i]){
				vis[x.top()]=0;
				x.pop();
			}
		}
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		while(x.size()) x.pop();
		start(i);
		for(int i=1;i<=m;i++){
			if(vis[i]){
				ans[i]++;
				vis[i]=0;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
