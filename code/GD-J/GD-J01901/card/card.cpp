//#include<c++bits/std.h>
#include<iostream>
using namespace std;
int a=1,a2,n,i=1,m,ans=0,j,dp[1000000],v[1000000]={0},vis[1000000]={0},l,t[1000000]={0};
string c1,s1,c2,s2;
char s;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>dp[i];
	}
	for(int i=1;i<=n;i++){

		for(int j=i;j<=n;j++){
			if(vis[dp[j]]==0){
				vis[dp[j]]=j;
				v[j]=dp[j];

			}else{
				for(int k=vis[dp[j]];k<j;k++){
					vis[v[k]]=0;
					v[k]=0;
					
				}
			}
		}
		for(int j=i;j<=n;j++){
			//cout<<v[j]<<" ";
			t[dp[j]]++;
			v[j]=0;
		}cout<<endl;
	}
	for(i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 
