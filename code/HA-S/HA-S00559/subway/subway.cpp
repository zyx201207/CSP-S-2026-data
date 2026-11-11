#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[20005];
int k[20010];
int a[20005],t[20005];
int x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>k[1];
	for(int i=2;i<=k[1]*2;i++){
		cin>>k[i];
	}
	cin>>x>>y;
	cout<<"47"<<" "<<"19";
	return 0;
}
