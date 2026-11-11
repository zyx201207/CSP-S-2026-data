#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],dp[200005]; 
long long big=-1;
void c(int s){
	if(s>=n)return ;
	for(int i=s;i<n;i++){
		dp[i]=a[i]&a[i+1];
		c(i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	c(0);
	for(int i=0;i<n;i++){
		big=max(big,dp[i]);
	}
	cout<<big;
	return 0;
}
