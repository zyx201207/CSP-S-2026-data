#include<bits/stdc++.h>
using namespace std;
long long cc,ccc,n,m,a[1000010];
int main(){
	freopen("migrate","r",stdin);
	freopen("migrate","w",stdout);
	cin>>cc>>ccc;
	for(int i=1;i<=ccc;i++){
		cin>>n>>m;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		long long b=a[2]-a[1];
		m/=b;
		m--;
		m*=2;
		cout<<n-m<<endl;
	}
	return 0;
}

