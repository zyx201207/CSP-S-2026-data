//GZ-J00411 贵阳市南明区华麟学校 张喆品  
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
char a[200020];
int b[200020];
long long cnt;
void dfs(int x,int y,int j,int k){

	if(x>=j){
		return ;
	}
	if(a[x]==a[j]){
		if(y>k){
			dfs(x,y-k,j-1,b[j-1]);
		}
		else if(k>y){
			dfs(x+1,b[x+1],j,k-y);
		}
		else{
			dfs(x+1,b[x+1],j-1,b[j-1]);
		}
	}
	else{
		if(y>k){
			cnt+=k;
			dfs(x,y-k,j-1,b[j-1]);
		}
		else if(k>y){
			cnt+=y;
			dfs(x+1,b[x+1],j,k-y);
		}
		else{
			cnt+=k;
			dfs(x+1,b[x+1],j-1,b[j-1]);
		}		
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		cin>>a[i];
	}
	dfs(1,b[1],n,b[n]);
	cout<<cnt;
	return 0;
}

