#include<bits/stdc++.h>
using namespace std;
int c,t,n,a[2000010];
long long d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=0;k<t;k++){
		cin>>n>>d;
		for(int i=0;i<n;i++)
			cin>>a[i];
		if(d>=2*(a[1]-a[0]))
			cout<<n-2<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
