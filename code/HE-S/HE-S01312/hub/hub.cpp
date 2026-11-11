#include<bits/stdc++.h>
using namespace std;
int n,m,a[5001],q,dp[1001][5001];
int r(int e[],int p,int t){
	int u=0;
	if(t==0){
		for(int i=1;i<=p;i++){
			int y=0;
			for(int j=1;j<=p;j++){
				if(a[i]==a[j])y++;
			}
			u=max(u,y);
		}
		return u;
	}
	for(int i=0;i<=p;i++){
		e[i]++;
		u=max(r(e,p,t--),u);
		for(int j=1;j<=p;j++){
			cout<<e[i]<<' ';
		}
		cout<<endl;
		e[i]--;
	}
	return u;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<r(a,n,m);
	return 0;
} 
