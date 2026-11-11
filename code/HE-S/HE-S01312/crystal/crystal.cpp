#include<bits/stdc++.h>
using namespace std;
int n,m,a[5001],q,dp[1001][5001];
int r(int a[],int p,int m){
	int u=0;
	if(m==0){
		for(int i=1;i<=n;i++){
			int y=0;
			for(int j=1;j<=n;j++){
				if(a[i]==a[j])y++;
			}
			u=max(u,y);
		}
		return u;
	}
	for(int i=0;i<=p;i++){
		a[i]++;
		u=max(r(a,p,m--),u);
		for(int j=1;j<=p;j++){
			cout<<a[i]<<' ';
		}
		cout<<endl;
		a[i]--;
	}
	return u;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<r(a,n,m);
	return 0;
} 
