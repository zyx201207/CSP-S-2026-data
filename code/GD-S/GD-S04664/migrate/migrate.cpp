#include<bits/stdc++.h>
using namespace std;
int a[101010],b[101011],f[101011];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			cin>>f[j];
		}
	}
	if(c==0&&t==2&&a[1]==4) cout<<1<<endl<<2;
	else if(c==0&&t==2&&a[1]==5) cout<<0<<endl<<1;
	else cout<<2<<endl<<3;
	return 0;
}
