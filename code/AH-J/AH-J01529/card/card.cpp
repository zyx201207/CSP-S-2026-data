#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],l[500005],c[500005],dp[500005],r[500055];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(c,0,sizeof(c)); 
	for(int i=1;i<=n;i++){
		l[i]=c[a[i]];
		c[a[i]]=i;
	}memset(c,0,sizeof(c)); 
	for(int i=n;i>=1;i--){
		r[i]=c[a[i]];
		c[a[i]]=i;
	}
	dp[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i-1]==a[i]){
			dp[i]=dp[i-1]+1;
		}else{
			dp[i]=dp[l[i]]+1;
			if(!(r[i-1]>i))dp[i]+=dp[i-1];
		}
	}for(int i=1;i<=n;i++){
		c[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<dp[c[i]]<<" ";
	}
	cout<<"\n";	return 0;
}
