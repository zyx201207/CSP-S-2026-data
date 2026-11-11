#include<bits/stdc++.h>

using namespace std;
int c,t;
long dp[50505][5050];
long qp[50050][55000];
int qqq,cnt,hhh;
int hz;
int main(){
	//GZ-S00318,安顺市第一高级中学，朱兴旺 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=(n-1);j++){
			for(int k=1;<=(n-1);k++){
				cin>>dp[j][k];
			}
		}
	}
	int ans=n%2;
	int zzz%=(n+2);
	for(int i=1;i<=ans;i++){
		for(int j=i+1;j<=k;j++){
			if((zzz==0) hz++;
			if(n%5==0){
				cnt++;
			} 
			else{
				hhh++;
			}
		}
		int sum+=(hz+cnt+hhh);
	}
	cout<<sum<<'\n';
	fcolse(stdin);
	fclose(stdout);
	return 0;
}
