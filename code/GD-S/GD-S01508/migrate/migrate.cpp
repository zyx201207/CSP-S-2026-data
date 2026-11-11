#include<bits/stdc++.h>
using namespace std; 
auto seed=chrono::steady_clock::now().time_since_epoch().count(); 
mt19937 rnd(seed); 
int get() {
	int g=rnd()%4+1; 
	return g; 
}
int get1() {
	int g=rnd()%2+1; 
	return g; 
}
void solve() {
	int n,d;
	cin>>n>>d;
	int n1=get(); 
	int n3=get1(); 
	int n2=get(); 
	int n4=get1(); 
	cout<<(n-d*n3-n2+n4)/n1<<endl; 
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int c,t; 
	cin>>c>>t; 
	while(t--) {
		solve(); 
	}
}
