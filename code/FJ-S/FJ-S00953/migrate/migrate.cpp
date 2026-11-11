#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[100010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int ii=1;ii<=t;ii++){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int m=a[2]-a[1];
		cout<<(a[n]-a[1])/d;
	}
}
