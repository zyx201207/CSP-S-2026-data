#include<bits/stdc++.h>
using namespace std;
long long a[2010],n,m,mx=0;
void dfs(long long x,long long y,long long sum){
	if(y==m){
		mx=max(mx,sum);
	}
	if(x>n){
		return;
	}
	dfs(x+1,y,sum);
	if(y<m){
		if(sum==-1){
			dfs(x+1,y+1,a[x]);
		}else{
			dfs(x+1,y+1,sum&a[x]);
		}
	}
	return;
}
int main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long xxx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xxx=max(xxx,a[i]);
	}
	if(m==1){
		cout<<xxx;
		return 0;
	}
	dfs(1,0,-1);
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
