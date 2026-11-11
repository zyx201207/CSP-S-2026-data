#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
#define int long long
using namespace std;
int a[2000005],dp[5005],mn[5005];int n,d,A=1; 
void slove1(){
	int ans=0;
	for(int st=1;st<=n;st++){
		for(int i=st;i<=n;i++){
			dp[i]=0;mn[i]=0x3f3f3f3f3f3f3f3f;
		}
		for(int i=st;i<=n;i++){
			
			int mnn=0x3f3f3f3f3f3f3f3f;
		//	if(a[st+1]-a[st]<=d)dp[st+1]=1,mn[st+1]=1;
			mn[st]=0;
			dp[st]=1;
			for(int j=i-1;j>=st;j--){
				if(a[i]-a[j]>d){
					break;
				}
				mnn=min(mnn,mn[j]);
			}
			mn[i]=mnn+1;
	//		cout<<"!!!"<<i<<" "<<mn[i]<<endl; 
			for(int j=i-1;j>=st;j--){
				if(a[i]-a[j]>d)break;
	//			cout<<j<<" "<<mn[j]<<endl;
				if(mn[j]==mn[i]-1)dp[i]+=dp[j];
				if(dp[i]>n){
					break;
				}
			}
			if(dp[i]==2)ans++;
	
		}
	}
	cout<<ans<<endl;
}
signed main(){
	int C,T;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		A=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])A=0;
		}
		slove1();
	}

	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/ 

