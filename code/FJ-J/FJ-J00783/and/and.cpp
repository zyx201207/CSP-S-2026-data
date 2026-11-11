#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005],n,m,ret=-999999999999;
void dfs(int m,int i,ll sum){
	if(m==0){
		ret=max(ret,sum);
		return ;
	}else{
		for(int k=i+1;k<n;k++){
			dfs(m-1,k,sum&a[k]);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		dfs(m-1,i,a[i]);
	}
	cout<<ret;
	return 0;
}
