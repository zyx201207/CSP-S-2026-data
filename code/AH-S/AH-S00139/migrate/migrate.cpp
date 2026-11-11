#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int n,m;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[1]+m>=a[n]){
			cout<<0<<endl;
			continue;
		}
		if(m==2){
			cout<<n-m-1<<endl;
			continue;
		}
		if(m==1){
			cout<<1<<endl;
			continue;
		}
		if(m==3){
			cout<<n-m+1<<endl;
			continue;
		}
		cout<<1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
