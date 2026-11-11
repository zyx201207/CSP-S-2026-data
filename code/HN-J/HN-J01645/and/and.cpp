#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,ans;
int an[N],bn[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>an[i];
		bn[an[i]]++;
	}
	for(int i=1;i<=N;i++){
		if(bn[i]>=m)ans=max(i,ans);
	}
	sort(an+1,an+n+1);
	int cnt=an[n];
	for(int i=n-1;i>n-m;i--){
		cnt=cnt&an[i];
	}
	cout<<max(ans,cnt); 
	return 0;
}
/*
±©Á¦ 
void dfs(int x,int xa,int he){
	if(xa==m){
		ans=max(ans,he);
		return;
	}if(x==n+1)return;
	if(xa==0)dfs(x+1,xa+1,an[x]);
	else dfs(x+1,xa+1,he&an[x]);
	dfs(x+1,xa,he);
}
*/

