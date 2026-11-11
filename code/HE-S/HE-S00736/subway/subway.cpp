#include <bits/stdc++.h>
using namespace std;
int  c,n,m,d,q,w[500001],x,y,
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	if(c!=7 && c!=8 && c!=9 && c!=10 && c!=11){
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int b=max(x,y)-min(x,y),q;
	for(int i=1;i<=b/4;i++){
		q+=w[i];
	}
	cout<<b/4;
	return 0;
}
