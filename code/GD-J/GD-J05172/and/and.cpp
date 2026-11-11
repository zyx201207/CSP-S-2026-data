#include<bits/stdc++.h>
using namespace std; 
const int N=3000+10;
long long n,m,arr[N],ans[N],k=0,vis[N];
long long tmp;
void dfs(int op,int step){
	if(step==m){
		for(int i=1;i<=m;i++){
			cout<<arr[ans[i]]<<" ";
		}
		tmp=arr[ans[1]];
		for(int i=2;i<=m;i++){
			tmp &=arr[ans[i]];
		}
		k=max(k,tmp);
		tmp=0;
		ans[step]=0;
		cout<<endl<<"--------------"<<endl;
		return;
	}
	for(int i=op+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			ans[++step]=i;
			if(step<=m){
				dfs(i,step);
				step--;
				vis[i]=0;
			}
		}
	}
	return;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		ans[1]=i;
		dfs(i,1);
		memset(ans,0,sizeof ans);
		vis[i]=0;
	}
	cout<<k;
	return 0;
}
