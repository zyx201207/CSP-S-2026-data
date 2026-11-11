#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int b[200005][30];
int vis[200005];
void manba(long long q,int p,int t){
	if(q%2==1)  b[p][t]=1;
	else b[p][t]=0;
	if(q==1) return ;
	q/=2;
	manba(q,p,t+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		manba(a[i],i,0);
	} 
	long long ans=0;
	for(int j=29;j>=0;j--){
		int sum=0,ls=0,sga[200005];
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				if(b[i][j]==1){
					sum++;
				}
				else{
					ls++;
					sga[ls]=i;
				} 
			}
		}
		if(sum>=m){
			long long mj=1;
			for(int i=1;i<=j;i++) mj*=2;
			ans+=mj;
			for(int i=1;i<=ls;i++) vis[sga[i]]=1;
		}
	}
	cout<<ans;
	return 0;
}
