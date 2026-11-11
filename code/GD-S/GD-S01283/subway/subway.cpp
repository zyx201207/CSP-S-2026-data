#include<bits/stdc++.h>
using namespace std;
const int maxn = 504;
const int maxq = 1e5+4;

vector<int>w,a[maxn],t[maxn];
int k[maxn],l[maxq],r[maxq];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	w.push_back(0);
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		w.push_back(x);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	for(int i=1;i<=q;i++)
		cin>>l[i]>>r[i];
	
	return 0;
}
