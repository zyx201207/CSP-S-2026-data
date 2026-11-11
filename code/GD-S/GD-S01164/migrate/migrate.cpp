#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[10010],f[10010],ans=1e9;
void dfs(int u,int r,long long step){
	if(u==r){
		ans=min(ans,step);
		f[step]++;
		return ;
	}
	for(int i=u+1;i<=r;i ++){
		if(a[i]-a[u]>d){
			break;
		}
		else {
			dfs(i,r,step+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i <= n;i ++){
			cin>>a[i];
		}
		int anss=0;
		for(int l = 1;l <= n;l ++){
			for(int r = l+1;r <= n;r ++){
				for(int i = 1;i <= n;i ++) f[i]=0;
				ans=1e9;
				dfs(l,r,0);
				if(ans==1e9) ans=ans;
				else if(f[ans]==2) anss++;
			}
		}
		cout<<anss<<endl;
	}
}














