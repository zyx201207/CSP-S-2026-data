#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
vector<int> a;
void dfs(int deep,int u,int s,int val){
	if(n-deep+1 < m-u)return;
	if(u==m){
		ans=max(ans,val);
		return ;
	}
	if(s==0){
		dfs(deep+1,u+1,1,a[deep]);
	}
	else{
		dfs(deep+1,u+1,1,val&a[deep]);
	}
	dfs(deep+1,u,s,val);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	a.assign(n+1,0);
	int pian_a=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(((a[i]+1)&a[i])==0){//A-13
			pian_a++;
		}
	}
	if(pian_a==n){//A-13
		sort(a.begin()+1,a.begin()+1+n);
		cout<<a[n-m+1]<<endl;
		exit(0);
	}
	if(m==n){//7
		int ans_pian_7=a[1];
		for(int i=2;i<=n;++i){
			ans_pian_7=ans_pian_7&a[i];
		}
		cout<<ans_pian_7<<endl;
		exit(0);
	}
	if(m==1){//6
		int ans_pian_6=0;
		for(int i=1;i<=n;++i){
			ans_pian_6=max(ans_pian_6,a[i]);
		}
		cout<<ans_pian_6<<endl;
		exit(0);
	}
	dfs(1,0,0,0);
	cout<<ans<<endl;
	return 0;
}
