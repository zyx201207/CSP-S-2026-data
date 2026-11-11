#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d,a[500005];
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		cout<<n-(1+d/(a[2]-a[1]));
	}
}
