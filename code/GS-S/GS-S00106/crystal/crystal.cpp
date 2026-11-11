#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=500002;
ll a[MAXN]; // 每颗水晶能量 
int n; // 数量
ll m; // 操作次数
int ok_special=true; // 是否为特殊性质
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	ll diff=a[2]-a[1]; // 差值 
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(ok_special&&a[i]-a[i-1]!=diff){
			ok_special=false;
		}
	}
	if(ok_special){
		int cnt=1;
		while(true){
			if(m<=0)break;
			if(m-cnt*diff<0)break;
			if(ans>=n||cnt>=n)break;
			++ans;
			m-=cnt*diff;
		}
	}
	cout<<ans<<'\n';
	return 0;
} 
