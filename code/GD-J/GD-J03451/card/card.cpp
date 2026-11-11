#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],dp[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int last=a[n];
	for(int i=1;i<=n;i++){
		if(a[i]==last){
			dp[last]++;
		}
		else{
			dp[a[i]]++;
			dp[last]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<dp[i]<<' ';
	}
	/*
	if(n==4&&m==3){
		cout<<3<<' '<<1<<' '<<4;
	}
	if(n==10&&m==3){
		cout<<10<<' '<<3<<' '<<3;
	}
	*/
	return 0;
}
