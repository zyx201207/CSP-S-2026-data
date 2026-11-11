#include<bits/stdc++.h>
using namespace std; 
const int N=2e5+10,inf=-1e9-10; 
int tr[N][2],tot=1,ed[N],out[N],d[N];
int n,m,mmax=inf,cnt; 
void ins(int x) {
	int g=0; 
	int p=1; 
	while(x) {
		int c=(x>>1)%2; 
		x>>=1;  
		if(!tr[p][c]) tr[p][c]=++tot;
		d[p]++;
		p=tr[p][c];   
	}ed[p]++; 
} 
void solve(int x,int P) {
	int g=0,p=1; 
	while(x) {
		int c=(x>>1)%2; 
		x>>=1;
		if(!tr[p][c]) continue; 
		g=g*2+c;
		if(p==P) break; 
		else p=tr[p][c]; 
	}
	cout<<g; 
}
void calc(int x) {
	int p=1; 
	int eed,edp; 
	while(x) {
		int c=(x>>1)%2; 
		x>>=1;
		if(!tr[p][c]) continue; 
		if(d[p]<m) solve(x,eed); 
		else if(ed[p]!=0) eed=p;  
		p=tr[p][c];  
	}
}
int main() {
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);  
	cin>>n>>m; 
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x; 
		ins(x); 
		mmax=max(mmax,x); 
	}
	calc(mmax); 
	return 0; 
}
