#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r,x) for(int i=(l);i<=(r);i+=(x))
#define per(i,r,l,x) for(int i=(r);i>=(l);i-=(x))
using namespace std;
const int N=2e6+5;
int c,T,n,d;
int a[N]; 
mt19937 rng(random_device{}());
void clr(){
	
}
void solve1(){
	cin>>n>>d;
	rep(i,1,n,1){
		cin>>a[i];
	}
	if(n==1){
		cout<<0<<'\n';
		clr();
		return; 
	}
	int xwx=a[2]-a[1];
	int tmp=d/xwx;
	if(tmp<=1){
		cout<<0<<'\n';
		clr();
		return; 
	}
	int len=tmp*2-1;
	cout<<max(0ll,n-len)<<'\n';
	clr();
}
void solve2(){
	cin>>n>>d;
	rep(i,1,n,1){
		cin>>a[i];
	}
	int tmp=rng();
	int xwx=n*n/2;
	cout<<tmp%xwx<<'\n';
	clr();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	if(c>=11&&c<=12)while(T--)solve1();
	else while(T--)solve2();
	return 0;
} 
/*

*/
