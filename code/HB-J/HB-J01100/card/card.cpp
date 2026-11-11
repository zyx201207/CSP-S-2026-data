#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7,M=3e5+7;
int n,m;
int a[N];
int ans[M],s[M];
int b[M],k[M];
void solve(int l){
	for(int i=l; i<=n; i++){
		if(!b[a[i]]) b[a[i]]=i;
		else{
			//cout<<b[a[i]];
			s[b[a[i]]+1]-=1,s[i+1]+=1;
		}
	}
	for(int i=l; i<=n; i++){
		s[i]=s[i-1]+s[i];
		if(s[i]>-1&&!k[a[i]]) ans[a[i]]++,k[a[i]]=1;
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		solve(i);
		for(int i=1; i<=5001; i++) b[i]=0;
		for(int i=1; i<=5001; i++) k[i]=0;
		for(int i=1; i<=5001; i++) s[i]=0;
	}
	for(int i=1; i<=m; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
