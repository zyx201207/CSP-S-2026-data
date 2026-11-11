#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],qzh[500005];
bool check(int x,int l){
	return a[x]*(x-l)-(qzh[l]-qzh[x])<=m;
}
int get(int x){
	int l = 0,r = x;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(x,mid)){
			r=mid;
		}else{
			l=mid;
		}
	}
	return x-r+1;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=-1e11;
	a[n+1]=1e11;
	qzh[n+1]=0;
	sort(a+1,a+1+n);
	for(int i = n;i>=1;i--){
		qzh[i]=qzh[i+1]+a[i];
	}
	int ans=1;
	for(int i = 1;i<=n;i++){
		ans=max(ans,get(i));
	}
	cout<<ans;
	return 0;
}
/*
求写j组迷惑行为
HN-S00014 HN-J00019
是二分我们有救了
凹了1.5h没救了 
*/

