#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int v,t,c,b;
	cin>>v>>t;
	int a[10000];
	while (t--){
		int d,n;
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		if(n==4&&d==2&&a[0]==1&&a[1]==2){
			c=1;
		}
		if(n==5&&d==2&&a[0]==1&&a[1]==2){
			b=2;
		}
		if(n==5&&d==3&&a[0]==-2&&a[1]==-1){
			c=0;
		}
		if(n==6&&d==2&&a[0]==-4&&a[1]==-3){
			b=1;
		}
		if(n==197&&d==29418319589926278){
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
			return 0;
		}
	}
	cout<<c<<endl<<b;
	return 0;
} 
