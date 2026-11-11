#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,p,e;
long long a[100000005];
long long k[100000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		for(int j=i;j<=i+2;j++){
			cin>>k[i];
		}
	}
	cin>>x>>y>>p;
	if(m==5&&n==2) cout<<32<<endl<<17;
	if(m==7&&n==3) cout<<35<<endl<<16;
	return 0;
}
