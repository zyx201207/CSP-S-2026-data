#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m;
int w[N],vmax=-2,sum=-1,ans=-2;
void dfs(int i,int sum,int j){
	if(j==m){
		ans=max(sum,ans);
		return;
	}if(i>n){
		return ;
	}
	dfs(i+1,sum&w[i],j+1);
	dfs(i+1,sum,j);
	
}
signed main(){
     freopen("and.in","r",stdin);
     freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		vmax=w[i];
		sum&=w[i];
	}
	if(m==1){
		cout<<vmax;
		return 0;
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	if(m==2){
		int www=-2;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				www=max(www,w[i]&w[j]);
			}
		}
		cout<<www;
		return 0;
	}
	if(n<=20){
		dfs(1,-1,0);
		cout<<ans;
	}
	else{
		cout<<vmax;
		return 0;
	}
	return 0;
}

