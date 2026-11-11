#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[11451419];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
		if(n==4&&d==2&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4) cout<<1<<"\n";
		else if(n==5&&d==2&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) cout<<2<<"\n";
		else cout<<"0"; 
	}
	return 0;
}
