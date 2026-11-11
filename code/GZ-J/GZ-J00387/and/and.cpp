//GZ-00387 贵阳市南明区华麟学校 杨博麟 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long ans,n,m,mx,b,c,d;
long long a[N];
void dfs(int cnt,long long res,int c){
	res=(res&a[c]);
	if(m==cnt){
		ans=max(ans,res);
		return ;
	}
	for(int i=c+1;i<=n;i++) dfs(cnt+1,res,i);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	d=b=(a[1]&a[2]);
	c=a[2];
	for(int i=2;i<n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		b=(b&a[i]);
		c=(c&a[i]);
		d=(d&a[i]);
	}
	cin>>a[n];
	b=(b&a[n]);
	c=(c&a[n]);
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		cout<<b;
		return 0;
	}
	if(m==n-1){
		cout<<max(c,d);
		return 0;
	}
	if(n<=2000){
		for(int i=1;i<=n;i++) dfs(1,a[i],i);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
}


