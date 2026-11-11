#include<bits/stdc++.h>
using namespace std;
vector<int> w,a[500001],t[500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,ti=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int z;
		cin>>z;
		w.push_back(z);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a1,t1;
			cin>>a1>>t1;
			a[i].push_back(a1),t[i].push_back(t1);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ti+=w[x];
		
	}
	
	return 0;
}
