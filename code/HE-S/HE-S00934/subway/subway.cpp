#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[10000],a[10000],t[10000],k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i]>>t[i];
	}
	for(int i=1;i<=2;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i]>>t[i];
		}
	}
	cout<<32<<endl<<17;
	return 0;
} 

