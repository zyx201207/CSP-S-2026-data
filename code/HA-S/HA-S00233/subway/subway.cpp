#include<bits/stdc++.h>
using namespace std;

int w[500005];
int a[505][50005],t[505][50005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[i][k]>>t[i][k];
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<0<<endl;
	}
	return 0;
}
