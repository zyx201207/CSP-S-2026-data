#include <bits/stdc++.h>
using namespace std;
long long n,m,num[200005]={},ans=0;
int dfs(int now,int pastnum,int ni){
	if(now!=m){
		int ma=0;
		for(int i=1;i<=n;i++)ma=max(dfs(now+1,pastnum&num[i],num[i]),ma);
		return ma;
	}else{
		return pastnum&ni;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen('and.in','r',stdin);
//	freopen('and.out','w',stdout);
	cin>>n>>m;
	long long ans=-1;
	for(int i=1;i<=n;i++){
	cin>>num[i];ans=max(ans,num[i]);}
	cout<<ans;
} 
