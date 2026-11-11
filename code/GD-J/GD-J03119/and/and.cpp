#include<bits/stdc++.h>
#define long long int
using namespace std;

bool cs0=0;

int cs(int cs1,string s){
	if(cs0==1){
		cout<<s<<":"<<cs1<<endl;
		
	}
	return cs1;
}
//±äÁ¿
int n,m;
int dp[200005];
int v[200005];
signed main(){
	if(cs0==0){
		ios::sync_with_stdio(0);
		cin.tie(0); 
		freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
	}
	
	//´úÂë 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=n;i>=1;i--){
		if(v[i]>dp[m]){
			dp[1]=v[i];
		for(int j=m;j>=1;j--){
			if(dp[j]==0){
				dp[j]=dp[j-i]&v[i];
			}else{
				dp[j]=max(dp[j],dp[j-i]&v[i]);
			}
			
		}
		for(int i1=1;i1<=m;i1++){
		cs(dp[i1],"dp");
	}
		}
		
	}
	int num=99999999;
	for(int i=1;i<=m;i++){
		num=min(dp[i],num);
	}
	cout<<num;
	return 0; 
} 
