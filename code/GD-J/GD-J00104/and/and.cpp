#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m;
int a[100005],dp[100005],vis[100005],c=0; 
int dg(int ai,int cnt){
	if(cnt==m-1){
		if(ai>c){
			c=ai;
		}
		return 0;
	}
	if(ai<=c){
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dg(ai&a[i],cnt+1);
			vis[i]=0;
		}
	}
	return 0;
}                                  
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dg(a[i],0);
		vis[i]=0;
		
	}
	cout<<c;
	return 0;
}
