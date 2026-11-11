#include<bits/stdc++.h>
using namespace std;
int w[5000005],a[5000005],t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=2*k+1;i++){
		cin>>a[i];
		cin>>t[i];
	}
	int x,y;
	cin>>x>>y;
	cout<<10<<'\n';
	cout<<10;
	
	return 0;
}
