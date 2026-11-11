#include<bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;

int n,m,cnt,maxx,ans;
int a[200005];
int res[200005];

void dg(int step){
	if(step==n+1){
		if(cnt!=m) return;
		int i=1;
		while(!res[i]) i++;
		
		int sum=a[i++];
		
		for(;i<=n;i++){
			if(res[i]) sum&=a[i];
		}
		ans=std::max(ans,sum);
		return;
	}
	cnt++;
	res[step]=1;
	dg(step+1);
	cnt--;
	res[step]=0;
	dg(step+1);
}

void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			ans=std::max(ans,i&j);
		}
	}
	
	cout<<ans;
}
int solve2(){
	std::random_shuffle(a+1,a+1+n);
	for(int i=1;i<=m;i++){
		ans=(i==1?a[i]:ans&a[i]);
	}
	return ans;
}
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) return false;
	}
	return true;
}
bool check1(){
	for(int i=1;i<=n;i++){
		if((1<<int(std::log2(a[i]+1)))-1!=a[i]) return false;
	}
	return true;
}
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(m==1){
			maxx=std::max(maxx,a[i]);
		}
		if(m==n){
			if(i==1) ans=a[i];
			else ans&=a[i];
		}
	}
	if(m==1){
		cout<<maxx;
	}
	else if(m==n){
		cout<<ans;
	}
	else if((1<<int(std::log2(n)))==n&&check()){
		cout<<0;
	}
	else if(check1()){
		std::sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	else if(m==2){
		solve1();
	}
	else if(n<=20){
		dg(1);
		cout<<ans;
	}
	else dg(0),cout<<std::max(solve2(),ans);
	return 0;
}
/*
5 3
31 3 1 15 7
*/

