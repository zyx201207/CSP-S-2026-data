#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[500005],a[500005],b[500005];

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;


	while(q--){
		cout<<c+n+m-d*q<<endl;
	}
	
	return 0;
}
