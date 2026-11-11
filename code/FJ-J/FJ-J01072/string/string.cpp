#include<bits/stdc++.h>
#define int long long
using namespace std;
map<pair<int,int>,int>dp;
int k[100050];
char d[100050];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	string c="";
	cin>>k[1]>>d[1];
	int sum=k[1];
	for(int i=2;i<=t;i++){
		cin>>k[i]>>d[i];
		sum=__gcd(sum,k[i]);
	}
	for(int i=1;i<=t;i++){
		k[i]=k[i]/sum;
		while(k[i]--){
			c+=d[i];
		}
	}
	string a="";
	string b="";
	int x=c.size();
	int ans=x/2;
	if(x%2==1){
		ans=x/2+1;
	}
	for(int i=0;i<=x/2-1;i++){
		a+=c[i];
	}
	for(int i=x-1;i>=ans;i--){
		b+=c[i];
	}
	a.insert(0," ");
	b.insert(0," ");
	int n=a.size();
	int m=b.size();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]==b[j]){
				dp[{i,j}]=max(dp[{i,j}],dp[{i-1,j-1}]+1);
			}
			dp[{i,j}]=max(dp[{i,j}],max(dp[{i-1,j}],dp[{i,j-1}]));
		}
	}
	dp[{n,m}]--;
	n--;
	cout<<(n-dp[{n,m}])*sum;
	return 0;
}
