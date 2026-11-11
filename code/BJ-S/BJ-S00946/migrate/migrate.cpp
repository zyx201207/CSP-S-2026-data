/*
% hZk
AKAKAKAK

*/
#include<bits/stdc++.h>
#define N 5001
#define ll long long
using namespace std;

int cnt[N][N];
int dp[N][N];
ll c,t,n,d,x[N],rightmx[N],pos;//,xz[N];
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e7;
			cnt[i][j]=0;
		}
		dp[i][i]=0;
	}
}
int getans(){
	init();
	pos=1;
	for(ll i=1;i<=n;i++){
		pos=max(pos,i);
		while(pos<n&&x[pos+1]-x[i]<=d)pos++;
		rightmx[i]=pos;
	}
	//for(int i=2;i<=n;i++){
	//	xz[i]=(rightmx[i-1]==rightmx[i-2]&&rightmx[i-1]==rightmx[i]);
	//}
	for(int i=n;i;i--){
		for(int j=i+1;j<=n;j++){
			if(rightmx[i]>=j){
				dp[i][j]=1;
				cnt[i][j]=1;
				continue;
			}
			dp[i][j]=dp[rightmx[i]][j]+1;
			if(dp[i][j]>=1e7){
				dp[i][j]=1e7;
				cnt[i][j]=0;
				continue;
			}
			int isok1=0,isok2=0,rg1=0,rg2=0;
			if(rightmx[i]>1)isok1=(dp[i][j]==dp[rightmx[i]-1][j]+1),rg1=rightmx[i]-1;
			if(rightmx[i]>2)isok2=(dp[i][j]==dp[rightmx[i]-2][j]+1),rg2=rightmx[i]-2;
			if(rightmx[i]-1==i){
				if(rightmx[i]>3)isok1=(dp[i][j]==dp[rightmx[i]-3][j]+1),rg1=rightmx[i]-3;
				else isok1=0,rg1=0;
			}else if(rightmx[i]-2==i){
				if(rightmx[i]>3)isok2=(dp[i][j]==dp[rightmx[i]-3][j]+1),rg2=rightmx[i]-3;
				else isok2=0,rg2=0;
			}
			cnt[i][j]=cnt[rightmx[i]][j];
			if(rg1&&isok1){
				cnt[i][j]+=cnt[rg1][j];
			}
			if(rg2&&isok2){
				cnt[i][j]+=cnt[rg2][j];
			}
			if(cnt[i][j]>2)cnt[i][j]=3;
		}
	} 
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2)ans++;
		}
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<getans()<<"\n";
	}
	return 0;
}