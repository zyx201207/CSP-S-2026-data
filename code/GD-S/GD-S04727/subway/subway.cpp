#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int c,n,m,d,q;
int w[555555],t[514][514];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(t,-1,sizeof(t)); 
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int aaa,www;
			cin>>aaa>>www;
			t[aaa][aaa]=www;
		}
	}
	while(q--){
		int qx,qy;
		cin>>qx>>qy;
		long long ans;
		ans=w[qx]+w[qy];
		cout<<ans<<"\n";
	}
	return 0;
}
