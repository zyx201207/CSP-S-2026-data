#include<bits/stdc++.h>
using namespace std;
int dp[114514];
int island[114514];
int mark;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,n,a,b,ans=0;
	cin>>c>>n;
	while(n--){
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			cin>>island[i];
		}
		for(int f=1;f<=a;f++){
		dp[f]=0;
		for(int i=f+1;i<=a;i++){
			if(island[i]-island[f]<=b){
				dp[i]=1;
				mark=i;
			}
		}for(int t=mark;t<=a;t++){
		for(int k=mark-1;k>=f;k--){
				if(island[t]-island[k]<=b){
					dp[t]+=dp[k];
				}
			}	
		}
		for(int i=f;i<=a;i++){
			if(dp[i]==2) ans++;
		}
	}
	cout<<ans-1<<endl;
	ans=0;
	}
	return 0;
}
