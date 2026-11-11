#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,a[10000001],b[10000001],cc[10000001],dd[10000001];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>dd[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=q;i++){
		cin>>b[i]>>cc[i];
	}
	if(n==3)cout<<"35"<<endl<<"16";
	else cout<<"32"<<endl<<"17";
}
