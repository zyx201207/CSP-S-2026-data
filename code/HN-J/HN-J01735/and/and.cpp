#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m,maxn=-2e9;
void dfs(int s,int sum,int z){
	if(z>=m){
		maxn=max(sum,maxn);
		return;
	}
	if(s>n){
		return;
	}
	if(z==0){
		dfs(s+1,sum+a[s],z+1);
		dfs(s+1,sum,z);

	}else{	
		//cout<<"a[s]="<<a[s]<<" "<<"sum="<<sum<<" "<<"z="<<z<<" ";
		dfs(s+1,sum&a[s],z+1);
		dfs(s+1,sum,z);
	//	cout<<"a[s]="<<a[s]<<" "<<"sum="<<sum<<" "<<"z="<<z<<" ";
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<maxn;
	return 0;
} 
//4 2
//3 15 12 12
