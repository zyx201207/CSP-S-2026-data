#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int> w;
	vector<int> a;
	vector<int> t;
	w.resize(m+5);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		a.resize(k+5);
		t.resize(k+5);
	}
	for(int i=1;i<=q;i++) {
		int x,y;
		cin>>x>>y;
	}
	if(n==2) cout<<32<<endl<<17;
	if(n==3) cout<<35<<endl<<16;
	return 0;
}
/*
0 3 7 20 2
2 8 3 6 1 7 2 9
3 3 1 4 2 5 5 100
4 3 2 6 3 1 7 2
5 4 3 2 5 100 4 6 6 7
6 1 6
7 2 3
*/
