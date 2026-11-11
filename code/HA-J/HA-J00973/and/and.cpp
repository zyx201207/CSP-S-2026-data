#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005],ans;
void pf2(){
	ans=a[n];
	for(int i=n;i>=n-m+1;i--){
		ans&=a[i];
	}
	return ;
}
void dfs(ll x,ll s,ll cnt){
	if(x>n){
		if(s==m)ans=max(ans,cnt);
		return ;
	}
	dfs(x+1,s,cnt);
	if(cnt==0){
		dfs(x+1,s+1,a[x]);
	}else{
		dfs(x+1,s+1,cnt&a[x]);
	}
	return ;
}
void maxx(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(sum<a[i])sum=a[i];
	}
	ans=sum;
	return ;
}
void maxx2(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	return ;
}
void man(){
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans&=a[i];
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	if(n<=20){
		dfs(1,0,0);
	}else if(n<=2000){
		if(m==1)ans=a[n];
		else if(m==2)maxx2();
		else if(m==n)man();
	}else {
	pf2();
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
