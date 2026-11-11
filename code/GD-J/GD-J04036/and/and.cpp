#include<bits/stdc++.h>
using namespace std;
#define _for(i,x,y,z) for(int i=x;i<=y;i+=z)
typedef long long ll;
const int N=3e5+5;
int n,a[N],m;
bool A(){
	map<ll,bool> p;
	_for(i,0,31,1)p[(1<<i)]=1;
	_for(i,1,n,1){
		if(!p[a[i]+1])return 0;
	}return 1;
}bool B(){
	_for(i,1,n,1){
		if(a[i]!=i-1)return 0;
	}return 1;
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	_for(i,1,n,1)cin>>a[i];
	if(m==n){
		int sum=a[1];
		_for(i,2,n,1)sum&=a[i];
		cout<<sum;
		return 0;
	}else if(A()||B()){
		sort(a+1,a+n+1,greater<int>());
		int sum=a[1];
		_for(i,2,m,1)sum&=a[i];
		cout<<sum;
		return 0;
	}else if(m*n*n<=1e8){
		int dp[n+5][m+5],sum=0;
		memset(dp,0,sizeof(dp));
		_for(i,1,n,1)dp[i][1]=a[i];
		_for(i,2,m,1){
			_for(j,1,n,1){
				_for(k,1,j-1,1){
					dp[j][i]=max(dp[j][i],dp[k][i-1]&a[j]);
				}if(i==m)sum=max(sum,dp[j][i]);
			}
		}cout<<sum;
		return 0;
	}else cout<<0;
}
