#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,mi[500005],t,w,k,a,b;
int main(){
	freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>mi[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>t>>w;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		cout<<q;
	}
	return 0;
}

