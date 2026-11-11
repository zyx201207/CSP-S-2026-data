#include<bits/stdc++.h>
using namespace std;
long long n,anss=0,m,a[200005],ans[200005],book[200005];
int gs(long long x){
	long long t=0;
	while(x!=0){
		if(x&1) t++;
		x=x>>1;
	}
	return t;
}
bool cmd(long long x,long long y){return gs(x)>gs(y);}
	
void dfs(long long num,long long dq){
	if(num>m){
		long long sum=ans[m];
		for(int i=1;i<=m;i++){
			sum&=ans[i];
		}
		anss=max(anss,sum);
		return;
	}
	if(dq<anss) return ;
	for(int i=1;i<=n;i++){
		if(book[i]) continue;
		book[i]=1;
		ans[num]=a[i];
		dfs(num+1,dq&ans[num]);
		book[i]=0;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmd);
	if(n<=2000||m==n-1){dfs(1,LLONG_MAX);cout<<anss;}
	else{
		anss=LLONG_MAX;
		//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		for(int i=1;i<=m;i++) anss&=a[i];
		cout<<anss;
	}
	return 0;
}

