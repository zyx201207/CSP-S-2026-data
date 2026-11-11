#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N],p[N],s[N],t[N];
int n;
ll m;
//计算区间操作次数 
ll calc(int l,int r){
	return s[r-1]-s[l-1]-(t[r-1]-t[l-1])*(l-1);
}
bool check(int k){
	for(int l=1;l<=n-k+1;l++){
		int r=l+k-1;
		if(calc(l,r)<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		p[i]=a[i+1]-a[i];
	}
	p[n]=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+i*p[i]; 
	}
	for(int i=1;i<=n;i++){
		t[i]=t[i-1]+p[i];
	}
	int ans=0;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
//我去，补药过来，怎么感觉全是图论的题啊？！
//我决定了，只打暴力！只打暴力！
//总分有三位数就行，球球了！ 
//嗯……但是好像如果这题不挂的话，就有三位数了呢？
//一个小时四十分钟也是终于把式子推出来了……
//我已死
//请让我上迷惑行为大赏吧……
//这是一个炸掉了的初二小蒟蒻的最后请求 
//已力竭 
