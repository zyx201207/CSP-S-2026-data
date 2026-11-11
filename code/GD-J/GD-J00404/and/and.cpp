#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],c[6],ans=0;
void dfs(int x,int y,int s){
	if(x==n+1){
		if(y==m) ans=max(ans,s);
		return ;
	}
	if(y<m) dfs(x+1,y+1,(s&a[x]));
	dfs(x+1,y,s);
}
void solve1(){
	dfs(1,0,INT_MAX);
	cout<<ans;
}
void solve2(){
	cout<<0;
}
void solve3(){
	int s=INT_MAX;
	for(int i=1;i<=n;i++){
		s&=a[i];
	}
	cout<<s;
}
void solve4(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) ans=max(ans,(a[i]&a[j]));
		}
	}
	cout<<ans;
}
void solve5(){
	for(int i=1;i<=n;i++){
		c[a[i]]++;
	}
	if(c[3]>=m) cout<<2;
	else if(c[3]+max(c[1],c[2])>=m) cout<<1;
	else cout<<0;
}
void solve6(){
	int s=INT_MAX;
	sort(a+1,a+n+1);
	for(int i=n-m+1;i<=n;i++){
		s&=a[i];
	}
	cout<<s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n<=20) solve1();
	else if(n<=2000){
		if(m==1) solve2();
		else if(m==n) solve3();
		else if(m==2) solve4();
	}
	else{
		if(mx<4) solve5();
		else solve6();
	}
	return 0;
}
