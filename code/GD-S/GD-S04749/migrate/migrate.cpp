#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000007],ans,m,cnt[2000007],f;
void dfs(int u,int e,int s){
	//if(t==0&&uu==1&&e==4) cout<<"*"<<u<<' '<<s<<endl;
	if(u>e) return ;
	if(u==e){
		cnt[s]++;
		return ;
	}
	for(int i=u+1;i<=n;i++){
		if(abs(x[i]-x[u])<=d){
			dfs(i,e,s+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//Oct31==Dec25?
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=1;k<=j-i;k++) cnt[k]=0;
				f=0;
				dfs(i,j,0);
				for(int k=1;k<=j-i;k++){
					if(cnt[k]!=0) {
						if(cnt[k]==2) {
							f=1;	
						}
						break;
					}
				}
				if(f) ans++;
			}
		} 
		cout<<ans<<endl;
	}
	return 0;
}
