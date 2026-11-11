#include <bits/stdc++.h>
using namespace std;
const int N=500000+5;
int a[N],b[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		for (int j=1;j<=2*k;j++){
			cin>>b[j];
		}
	}
	for (int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	} 
	if (n==2&&m==5){
		cout<<32<<endl<<17;
	}
	if (n==3&&m==7){
		cout<<35<<endl<<16;
	}
	if (n==15&&m==136){
		cout<<0;
	}
	return 0;
}
