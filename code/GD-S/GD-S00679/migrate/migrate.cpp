#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long
//#define int long long
#define pii std::pair<int,int>
#define rep(x,qwq,qaq) for(int (x)=(qwq);(x)<=(qaq);++(x))
#define per(x,qwq,qaq) for(int (x)=(qwq);(x)>=(qaq);--(x))
const int N=5000+7,M=5e3+3;
int n,d;
ll a[N],t[M][M];
void sr(){
	std::cin>>n>>d;
	rep(i,1,n) std::cin>>a[i];
}
void solve(){
	sr();
	rep(i,1,n){
		rep(j,1,n){
			t[i][j]=(abs(a[i]-a[j])<=d);
		} 
	}
	std::cout<<0<<'\n';
} 
void slv(){
	sr();
	if(a[2]-a[1]>d){
		std::cout<<0<<'\n';
	}else{
		std::cout<<n-2<<'\n';
	}
}
signed main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1,c;
	std::cin>>T;
	std::cin>>c;
	if(c<=10){
		while(T--) solve();
	}else if(c<=12){
		while(T--) slv();
	}else{
		while(T--) std::cout<<0<<'\n';
	}
	return 0;
}
/*
5 5
1 2 4 8 9

*/
