#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans;
int a[N];
void solve1(){
	sort(a+1,a+n+1);
	int k=a[n];
	for(int i=n-1;i>n-m;i--){
		k&=a[i];
	} 
	cout<<k;
}
void dg(int k,int t,int p){
	if(t>=m){
		if(p>ans){
			ans=p;
		}
		return ;
	}
	if(k>n) return ;
	dg(k+1,t+1,p&a[k]);
	dg(k+1,t,p);
}
void solve2(){
	dg(1,0,INT_MAX);
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=30) solve2();
	else solve1();
	return 0;
}
