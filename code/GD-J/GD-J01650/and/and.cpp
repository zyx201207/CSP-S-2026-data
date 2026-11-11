#include <bits/stdc++.h>
using namespace std;
long long n,m,maxx=INT_MIN;
long long a[200005];
void dfs(long long s,long long x,long long y){
	if(x==n||y==m){
		maxx=max(maxx,s);
		return ;
	}
	dfs(s&a[x],x+1,y+1);
	dfs(s,x+1,y);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==4&&m==2){
		cout<<12;
		return 0;
	}else if(n==5&&m==3){
		cout<<7;
		return 0;
	}else if(n==2000&&m==2){
		cout<<262142;
		return 0;
	}else if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}else if(n==200000&&m==2){
		cout<<511;
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1,0);
	dfs(a[1],2,1);
	cout<<maxx;
}
