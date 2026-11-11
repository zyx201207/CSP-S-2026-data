#include<bits/stdc++.h>
using namespace std;
int c,t,ans,tt,a[2000005],b[2000005];
void dfs(int st,int x,int ed,int k,int d,int kk){
	if(x>=ed){
		if(k==kk){
			cout<<st<<" "<<ed<<" "<<k<<endl;
			tt++;
		}
		if(tt==2){
			ans++;
			//cout<<st<<" "<<ed<<" "<<k<<endl;
			tt++;
		} 
		return;
	}
	if(k>kk) return;
	for(int i=1;i<=1e9;i++){
		if(x+i>b[x]) break;
		dfs(st,x+i,ed,k+1,d,kk);
	}
	return;
}
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		ans=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-1;i++){
			int h=a[i]+d;
			b[i]=i+1;
			for(int j=n;j>=i+1;j--){
				if(a[j]<=h){
					b[i]=j;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				
				tt=0;
				int u=i,k=0;
				while(u<j){
					u=b[u];
					k++;
				}
				cout<<i<<" "<<j<<" "<<k<<endl;
				dfs(i,i,j,0,d,k);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
