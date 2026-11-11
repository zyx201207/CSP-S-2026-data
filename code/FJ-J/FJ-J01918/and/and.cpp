#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using pii = pair<int,int> ;
int n,m,a[200100];
int mx=-INF;
void dfs(int x,int cnt,int sum){
	if(x==n+1||cnt==m){
		if(cnt!=m)return ;
		mx=max(mx,sum);
		return ;
	}
	if(sum!=-1)dfs(x+1,cnt+1,sum&a[x]);
	else dfs(x+1,cnt+1,a[x]);
	dfs(x+1,cnt,sum);
}
void p25(){
	dfs(1,0,-1);
	cout<<mx;
	return ;
}
void p30(){
	int mx1=-INF;
	for(int i=1;i<=n;i++){
		mx1=max(mx1,a[i]);
	}
	cout<<mx1;
}
void p35(){
	int ans=a[1];
	for(int i=2;i<=n;i++){
		ans&=a[i];
	}
	cout<<ans;
}
void p50(){
	int mx2=-INF;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			mx2=max(mx2,a[i]&a[j]);
		}
	}
	cout<<mx2;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20)p25();
	else if(m==1)p30();
	else if(m==n)p35();
	else if(n<=2000&&m==2)p50();
	else{
		sort(a+1,a+1+n);
		cout<<a[m];
	}
	return 0;
}
/*
4 2
3 15 12 12
3&15=3;
0011
1111
1100
*/
