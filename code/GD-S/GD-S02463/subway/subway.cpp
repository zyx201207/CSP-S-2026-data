#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define filename "subway" 

int n,m,c,d,q,k;
struct stat{
	int id,w;
}st[500005];
struct road{
	int v,u,w;
}r[500005];

signed main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	
	cin >>c>> n>>m>>d>>q;
//	if(c==0){
//		if(m == 479521){
//			cout <<
//		}
//	} 
	for(int i = 1;i<=m;i++){
		cin >> st[i].w;
		st[i].id = i;
	}
	
	for(int i = 1;i<=n;i++){
		cin >>k;
		for(int j = 1;j<=k;j++){
			
		}
	}
	
	return 0;
}
