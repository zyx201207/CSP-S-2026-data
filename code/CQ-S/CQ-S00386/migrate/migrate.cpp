#include<bits/stdc++.h>
using namespace std;
long long c,p,a[2001000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>p;
	while(p--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}int k=a[2]-a[1];
		int f=m/k;
		cout<<n-f-f+1<<endl;
	}
	return 0;
	
} 
