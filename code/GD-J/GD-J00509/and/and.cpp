#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200010];
ll dp[10010][10010];//bag dp
//fuction i:1->n j:m->1 
//dp[i]=max(dp[j-w[i]]+v[i],dp[i])
ll n,m;
char he(char c1,char c2){
	if(c1=='1'&&c2=='1') return '1';
	else return '0';
}
ll fand(ll x,ll y){
	ll r=0;
	string s1="",s2="",sans="";
	while(x){
		s1+='0'+(x%2);
		x/=2;
	}
	while(y){
		s2+='0'+(y%2);
		y/=2;
	}
	ll l1=s1.size(),l2=s2.size();
	if(s1.size()<s2.size()){
		for(int i=0;i<l2-l1;i++){
			s1+='0';
		}
	}
	else{
		for(int i=0;i<l1-l2;i++){
			s2+='0';
		}
	}
	for(int i=0;i<s1.size();i++){
		sans+=he(s1[i],s2[i]);
	}
	//cout<<s1<<endl<<s2<<endl<<sans<<endl;
	for(int i=sans.size()-1;i>=0;i--){
		r=r*2+sans[i]-'0';
	}
	return r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll i,j;
	for(i=1;i<=n;i++){
		cin>>a[i];dp[i][1]=a[i];
	}
	for(i=1;i<=n;i++){
		for(j=m;j>=1;j--){
			dp[i][j]=max(max(dp[i-1][j],fand(dp[i-1][j-1],a[i])),dp[i][j]);
		}
	}
	//for(i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<dp[n][m];
	return 0;
}
