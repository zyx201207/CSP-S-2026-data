#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2222222],ans,cnt,ti;
void qf(int x,int y,int z){
	if(x==y){
		ti=z;
		return ;
	}
	for(int i=y;i>x;i--){
		if(a[i]-a[x]<=d){
			qf(i,y,z+1);
			return ;
		}
	}
}
void dfs(int x,int y,int z){
	if(z>ti){
		return ;
	}
	if(x==y){
		cnt++;
	}
	for(int i=x+1;a[i]-a[x]<=d&&i<=y;i++){
		dfs(i,y,z+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			int p=d/(a[2]-a[1]);
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					if((j-i)%p==0){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				cnt=0;
				qf(i,j,0);
				dfs(i,j,0);
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	
	
	
	return 0;
}
