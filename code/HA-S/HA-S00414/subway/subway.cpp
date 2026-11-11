#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[100086],a[1008][1008],t[1020][1012];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=k;l++){
				cout<<w[i];
			}
		}
	}
	return 0;
}

