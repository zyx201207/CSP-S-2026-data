#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],r,l,ans,num,wer,dis[2000005],mp[305][305];
void dfs(long long k,long long sum){
	if(ans>=3){
		return;
	}
	if(k==r){
		ans++;
		return;
	}
	for(int i=min(dis[k],r);i>=k+1;i--){
		if(sum+1+mp[i][r]>mp[l][r]){
			break;
		}
		dfs(i,sum+1);
		if(ans>=3){
			return;
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		wer=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			dis[i]=0;
			for(int j=1;j<=n;j++){
				mp[i][j]=-52013697891;
			} 
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					dis[i]=j;
				}else{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			int kkk=1;
			for(int j=i+1;j<=n;j++){
				int k=dis[j-1];
				if(k==0){
					break;
				}
				for(int l=j;l<=k;l++){
					mp[i][l]=kkk;
				}
				j=k;
				kkk++;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=0;
				r=j;
				l=i;
				dfs(i,0);
				if(ans==2){
					wer++;
				}
			}
		}
		cout<<wer<<"\n";
	}
	return 0;
}
