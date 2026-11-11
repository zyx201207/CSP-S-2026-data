#include<bits/stdc++.h>
using namespace std;
long long n,d,t,c;
int a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=0;j<=n;j++){
			cin>>a[j];
		}
	}
	return 0;
}
