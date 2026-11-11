#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k_i;
#define x first
#define y second
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+5),k(n+5);
	vector<int> a[],t[];
	vector<pair<int,int>>s;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k_i;
		k.push_back(k_i);
		for(int j=1;j<=2*k_i;j++)cin>>a[i][j]>>k[i][j];
	} 
	
	 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
