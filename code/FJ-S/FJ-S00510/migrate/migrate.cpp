#include<bits/stdc++.h>
using namespace std;
int c,t,cnt=0,a[2000001],n,m,vis[2000001];
void asd(int x,int y,int time){
	if(a[y]-a[x]<=m&&time==0){
		vis[1]=1;
		return;
	}
	if(x==y){
		vis[time]+=1;
		return;
	}
	for(int i=x+1;i<=y;i++){
		if((a[i]-a[x])<=m){
			asd(i,y,time+1);
		}else{
			break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		memset(a,0,sizeof(a));
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				memset(vis,0,sizeof(vis));
				asd(i,j,0);
				for(int k=1;k<=2000001;k++){
					if(vis[k]!=0){
						if(vis[k]==2){
							ans+=1;
							//cout<<k<<' '<<i<<' '<<j<<endl;
							break;
						}
					}
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
