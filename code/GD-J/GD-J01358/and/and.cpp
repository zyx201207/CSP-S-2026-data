#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,m,a[N],maxx,yu;
int b[N];
unordered_map<int,bool>mp;
void dfs(int x,int k){
	if(k==m){
		int t=b[1];
		for(int i=2;i<=m;i++){
			t&=b[i];
		}
		maxx=max(maxx,t);
		return ;
	}
	if(x>n) return ;
	b[k+1]=a[x];
	dfs(x+1,k+1);
	b[k+1]=0;
	dfs(x+1,k);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];yu=a[1];
	maxx=max(maxx,a[1]);
	for(int i=2;i<=n;i++)
		cin>>a[i],maxx=max(maxx,a[i]),yu=(yu&a[i]);
	for(int i=0;i<=30;i++)
		mp[pow(2,i)-1]=1;
	bool f=1,f2=1;
	for(int i=1;i<=n;i++){
		if(mp[a[i]]==0) f=0;
	}
	for(int i=1;i<=n;i++)
		if(a[i]!=i-1) f2=0;
	sort(a+1,a+1+n,greater<int>());
	if(m==1){
		cout<<maxx;
	}else if(m==n){
		cout<<yu;
	}else if(m==2){
		maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				maxx=max(maxx,a[i]&a[j]);
		}
		cout<<maxx;
	}else if(f==1){
		cout<<a[m];
	}else if(f2==1){
		int k=a[1];
		for(int i=2;i<=m;i++)
			k&=a[i];
		cout<<k;
	}else{
		maxx=0;
		dfs(1,0); 
		cout<<maxx;
	}
	return 0; 
}
/*
5 3
31 3 1 15 7
4 2
3 15 12 12
*/
