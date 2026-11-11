#include<bits/stdc++.h>
using namespace std;
int n,m,num[200005][32],a[2005],sum[32],ans=0,vis[200005];
int zans[32];
int kkk=1,xty=0;
void work(int k,int r){
	int s=k,tp=0;
	while(s){
		if(s%2==1)num[r][++tp]=1;
		else num[r][++tp]=0;
		s/=2;
	}
	num[r][0]=tp;
}
bool check1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=num[i][0];j++){
			if(num[i][j]==0)return 0;
		}
	}
	return 1;
}
void orb(){
	for(int i=num[n][0];i>=1;i--){
		if(sum[i]>=m){
			zans[i]=1;
			for(int j=1;j<=n;j++){
				if(num[j][i]==0&&vis[j]==0){
					vis[j]=1;
					for(int k=1;k<=num[j][0];k++){
						if(num[j][k]==1){
						//	cout<<k;
							sum[k]--;
						//	cout<<" "<<sum[k]<<endl;
						}
					}
				}
			} 
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(vis,0,sizeof(vis));
	memset(zans,0,sizeof(zans));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		work(a[i],i);
	}
	for(int i=1;i<=num[n][0];i++){
		for(int j=1;j<=n;j++){
			if(num[j][i]==1)sum[i]++;
		}
	}
	if(check1()){
		int ans=a[n]&a[n-1]&a[n-2];
		cout<<ans;
		return 0;
	}
	orb();
	
	for(int i=1;i<=num[n][0];i++){
		if(zans[i]!=0)xty+=kkk;
		kkk*=2;
	}
	cout<<xty;
	return 0;
} 
