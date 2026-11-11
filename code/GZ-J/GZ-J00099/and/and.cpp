//GZ-J00099 杜晨嘉
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200001];
long long mx=-1;
bool lly[200001];
void dfs(int s,long long z){
	if(s==m){
		mx=max(mx,z);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!lly[i]){
			lly[i]=1;
			dfs(s+1,z&a[i]);
			lly[i]=0;
		}
	}
}
//long long dp[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	/*for(int i=1;i<=m;i++){
		dp[i]=
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[j]=dp[m-j]&a[i];
		}
	}
	cout<<dp[m];*/
	for(int i=1;i<=n;i++){//暴力
		lly[i]=1;
		dfs(1,a[i]);
		lly[i]=0;
	}
	cout<<mx;
	/*int s;//输出对应二进制数
	cin>>s;
	while(s>0){
		cout<<s%2;//反过来才是
		s/=2;
	}*/
	/*string s;//输出对应十进制数
	cin>>s;
	long long t=0,j=0;
	for(int i=s.size()-1;i>=0;i--){
		t+=pow(2,j)*int(s[i]-'0');
		j++;
	}
	cout<<t;*/
	return 0;
}
