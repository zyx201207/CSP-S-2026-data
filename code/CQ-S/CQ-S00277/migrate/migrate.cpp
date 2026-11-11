#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,N6=305,N2=15;
int n,cnt[N6][N6][N6];
long long d,a[N];
//void subtask6(){
//	for(int r=1;r<=n;r++){
//		for(int l=1;l<r;l++){
//			if(a[r]-a[l]<=d){
//				cnt[l][r][1]=1;
//			}else{
//				for(int )
//			}
//		}
//	}
//}
int minn[N2][N2],mins[N2][N2];
void dfs(int st,int ed,int sum){
	if(sum<minn[st][ed]){
		minn[st][ed]=sum;
		mins[st][ed]=1;
	}else if(sum==minn[st][ed]){
		mins[st][ed]++;
	}else{
		return;
	}
	for(int i=ed+1;i<=n;i++){
		if(a[i]-a[ed]>d) break;
		dfs(st,i,sum+1);
	}
}
void dcsl(){
	if(n<4){
		cout<<0<<"\n";
		return;
	} 
	d/=(a[n]-a[n-1]);//一次最多跳几个点->问题变为点之间位置差为1 
	if(d<2){
		cout<<0<<"\n";
		return;
	} 
	cout<<max(0ll,(n-(d*2)+1))<<"\n"; 
}
void solve(int TT){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(TT==1||TT==2){//8pts
		memset(minn,0x3f,sizeof(minn));
		memset(mins,0,sizeof(mins));
		for(int i=1;i<=n;i++){
			dfs(i,i,0);
		}
		int ans=0;
		for(int l=1;l<=n;l++){
			for(int r=l+3;r<=n;r++){
				if(mins[l][r]==2){
					ans++;
				}
			} 
		}
		cout<<ans<<"\n";
		return;
	}
	if(TT==11||TT==12){//8pts
		dcsl();
		return;
	}
//	if(TT<=6){
//		subtask6();
//		return;
//	}
//	for(int l=1,r=1;l<=n;l++){
//		while(r<n&&a[r+1]-a[l]<=d){
//			r++;
//		}
//	}
//	long long ans=0;
//	for(int i=1,l=1,r=1;i<=n;i++){
//		
//	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1,TT;
	cin>>TT>>T;
	while(T--){
		solve(TT);
	}
	return 0;
}
/*
1 3
4 2
1 2 3 4
5 2
1 2 3 4 5
5 3
-2 -1 0 1 2

1 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
