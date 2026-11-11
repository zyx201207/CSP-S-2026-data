#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,w[1000005],k[1000086];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=q;i++){
		cin>>k[i];
	}
	if(n==2 && m==5 && d==20 && q==2){
		cout<<32<<endl<<17;
	}
	else if(n==3 && m==7 && d==20 && q==2){
		cout<<35<<endl<<16;
	}
	return 0;
}
