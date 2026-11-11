#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],i,j,k,p,c[M]; vector<int> b; bool v[N];
int main() {
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	freopen("card.in","r",stdin),freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;++i) cin>>a[i];
	for(k=1;k<=n;++k) {
		b.clear();
		for(i=0;i<=n;++i) v[i]=0;
		for(i=k;i<=n;++i) {
			for(j=0;j<(int)b.size();++j) if(b[j]==a[i]&&!v[j]) 
				for(;j<(int)b.size();++j) v[j]=1;
			b.push_back(a[i]);
		}
		for(i=0;i<(int)b.size();++i) if(!v[i]) ++c[b[i]];
	}
	for(i=1;i<=m;++i) cout<<c[i]<<' ';
	return 0;
}
// rp++;
/*
4 3
1 2 1 3

3 1 4

10 3
3 1 2 1 3 2 3 1 2 1

10 3 3
*/
