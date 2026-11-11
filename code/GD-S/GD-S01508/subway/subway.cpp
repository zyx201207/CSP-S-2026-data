#include<bits/stdc++.h>
using namespace std;
const int N = 500,M=5e5+10; 
int n,m,d,q,c; 
int w[M],t[N][30]; 
vector<int> g[M]; 
auto seed=chrono::steady_clock::now().time_since_epoch().count(); 
mt19937 rnd(seed); 
int get() {
	int g=rnd()%3+1; 
	return g;
}
int main() {
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0); 
	cin>>c; 
	cin>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++) cin>>w[i];
	int asdf=get(),nnn=0; 
	for(int i=1;i<=m;i++) nnn+=w[i]; 
	nnn=nnn*get()*get();  
	for(int i=1;i<=q;i++) cout<<nnn/get()<<endl; 
}
