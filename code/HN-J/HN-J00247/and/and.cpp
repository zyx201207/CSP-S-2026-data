#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200026],ma=-1;
bool use[200026];
void dfs(int x,int num,int deep){
	if(deep==m){
		ma=max(ma,num);
		return;
	}
	use[x]=1;
	for(int i=1;i<=n;i++){
		if(!use[i]){
			dfs(i,num&a[i],deep+1);
		}
	}
	use[x]=0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);//È¥×¢ÊÍ£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		dfs(i,a[i],1);
	}
	cout<<ma;
	return 0;
}
