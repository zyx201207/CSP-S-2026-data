#include <bits/stdc++.h>
using namespace std;
#define int long long 
int C,T,n,d,x[5000005],ans;
int minlen(int u,int v){
	for(int i=u+1;i<=v;i++)if(x[i]-x[i-1]>d)return -1;
	if(u==v)return 0;
	int nx=u;
	while(x[nx]-x[u]<=d&&nx<=n)nx++;nx--;
	return minlen(nx,v)+1;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);  

	cin>>C>>T;
	while(T--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int u=1;u+3<=n;u++){
			/*
			zhe ti shi cuo ti ba!
			yang li 3 shou suan di 2 zu de ans ye bu dui 
			*/
			
			 
			if(
			
			x[u+1]-x[u]<=d &&//12
			x[u+3]-x[u+2]<=d &&//34
			x[u+2]-x[u]<=d &&//24
			x[u+3]-x[u+1]<=d&&//13
			x[u+3]-x[u]>d//14
			 
			){
			ans++;
			for(int i=u+3+1;i<=n&&x[i]-x[i-1]<=d&&x[i]-x[u+2]>d;i++)ans++;
			
			
			}
		}cout<<ans<<"\n";
	}
	
}
