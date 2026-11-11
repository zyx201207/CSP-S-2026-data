#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int c,t;
int dis[N];
int dp[N]; 
int b[N];
int x[N];
int dis_r[N];
signed main(){
	freopen("migrate2.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	
	while(t--){
		
		int n,d;
		cin>>n>>d;
		
		for(int i = 1;i<=n;i++){
			dp[i]=0;
			b[i]=0;
		}
		
		for(int i =1;i<=n;i++){
			cin>>x[i];
		}
		
		int j=1;
		for(int i = 1;i<=n;i++){
			while(x[i]-x[j]>d&&j<i){
				j++;
			}
			if(x[i]-x[i-1]>d){
				n=i;
				break;
			}
			dis[i]=i-j+1;
			//dis[i]表示i可以从i-dis[i]+1个位置跳过来 
		}
		j=n;
		for(int i = n;i>=1;i--){
			while(x[j]-x[i]>d&&j>i){
				j--;
			}
			dis_r[i]=j-i+1;
			//dis[i]表示i可以从i-dis[i]+1个位置跳过来 
		}
		dp[0]=1;
		j = 1;
		b[0]=1;
		int j1=1;
		for(int i = 1;i<=n;i++){
		//	dp[i]=max(dp[i],dp[i-dis[i]+1]);
			int l = 1,r=n;
			int ansl=0;
			while(l<=r){
				int mid=l+r>>1;
				if(mid+dis_r[mid]-1>=i){
					r=mid-1;
					ansl=mid;
				}else{
					l=mid+1;
				}
			}
		//	cout<<ansl<<'\n';
			//ansl左边最后一个能到达i的点
			//ans2右边最后一个能到达i的点
			//获取只落在ansl和ansl+1点上的点
			int f=0;
			int last=1;
			
			for(j1;j1<=i;j1++){
				if(j1+dis_r[j1]==ansl+1){
					if(f==0)last=j1;
					f=1;
				}
				if(j1+dis_r[j1]>ansl+1){
					j1--;
					break; 
				}
			}
			
			
			if(j+dis_r[j]-1==ansl+1){
				dp[i]+=b[j]-b[last-1]+1;
			}
		
			
			
			b[i]=b[i-1]+dp[i];
		}
		
		int ans=0;
		
		for(int i =1;i<=n;i++){
			ans+=dp[i];
	//		cout<<dp[i]<<' ';
		}
		
		cout<<ans;
//		
//		for(int i = 1;i<=n;i++){
//			cout<<dis[i]<<' ';
//		}
//		
//		cout<<'\n';
	//	for(int i =1;i<=n;i++){
	//		cout<<dis_r[i]<<' ';
	//	}

		cout<<'\n';
	}
	
	
	return 0;
}
