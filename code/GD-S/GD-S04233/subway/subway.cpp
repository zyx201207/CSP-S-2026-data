#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
vector<int>a[500505],mn[500505];
void dj(int x){
	int mn2=1e9;
	 for(int i=1;i<=m+n;i++){
	 	if(a[x][i]!=0){
	 		mn2;
		 }
	 }
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int b,x;
			cin>>b>>x;
			a[i+n][b]=x;
			a[b][i+n]=x;
		}
	}
	for(int i=0;i<=m;i++){
		mn[i].push_back(1e9);
	}
	dj(1);
	return 0;
}
