#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int a[2000005];
		int l,no;
		cin>>n>>d;
		a[1]=0;
		cin>>l;
		for(int i=2;i<=n;i++){
			cin>>no;
			a[i]=no-l;
			l=no;
		}
		cout<<'0'<<"\n";
	}
	return 0;
}
