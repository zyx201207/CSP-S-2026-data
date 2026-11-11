#include<bits/stdc++.h>
using namespace std;
#define int long long
//YE@H BR0 UR RiGHt
bool baoli=0;
int a[500067],maxcrystal=-1,crystal[67],n,m;
void dfs(int step,int loc,int tar){
	baoli=1;
	if(step==tar+1){
		int cost=0;
		for(int i=1;i<=tar;i++){
			cost+=(a[crystal[tar]]-a[crystal[i]]);
		}if(cost<=m)maxcrystal=max(maxcrystal,tar);
	}else{
		for(int i=loc;i<=n-tar+step;i++){
			crystal[step]=i;
			dfs(step+1,i+1,tar);
		}
	}
}void doAB(){
	int cha=a[2]-a[1];
	int ans=1;
	for(int i=1;i<n;i++){
		int cost=cha*i*(i+1)/2;
		if(m>=cost)ans=i+1;
		else break;
	}cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+n+1);
	if(n>5000)doAB();
	else for(int i=1;i<=n;i++)dfs(1,1,i);
	if(baoli)printf("%lld",maxcrystal);
	return 0;
}