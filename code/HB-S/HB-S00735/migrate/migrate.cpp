#include<bits/stdc++.h>
using namespace std;
long long n,ans[100005],len=0;
void dfs(int idx,int aim){
	if(idx>aim){
		for(int i=1;i<=aim;i++) cout<<ans[i];
		cout<<",";
		len++;
		return;
	}
	ans[idx]=78;dfs(idx+1,aim);
	ans[idx]=91;dfs(idx+1,aim);
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){dfs(1,i);}
	cout<<endl<<len;
	return 0;
}

