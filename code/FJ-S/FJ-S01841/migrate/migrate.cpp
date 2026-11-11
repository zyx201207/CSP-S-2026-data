#include<bits/stdc++.h>
using namespace std;
long long ans,s,minn=2e6+5,c,t,n,d,a[2000024];
void dfs(int x,int y,long long step){
	if(x==y){
		if(step==minn)s++;
		else if(step<minn){
			s=1;
			minn=step;
		}return ;
	}for(int i=x+1;i<=y;i++){
		if(abs(a[i]-a[x])<=d){
			dfs(i,y,step+1);
		}else break;
	}return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				minn=2e6+5,s=0;
				dfs(i,j,0ll);
				if(s==2)ans++;
			}
		}cout<<ans<<endl;
	}return 0;
}
