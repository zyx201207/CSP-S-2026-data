#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
long long dp[10000][10000];
struct node{
	int w,num;
}h[100000];
int mar,ans;
int f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
				if(a[i]<a[j]){
					dp[i][j]=-1;
				}else if(a[i]>=a[j]){
					dp[i][j]=a[i]-a[j];
					ans+=dp[i][j];
					mar++;
				}
		}
	    h[i].w=ans;
	    h[i].num=mar;
	    ans=0;
	    mar=0;
	}
	for(int i=1;i<=n;i++){
		if(h[i].w!=0&&h[i].w<=m){
	     f=max(f,h[i].num);		
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<f;
   return 0;
}
