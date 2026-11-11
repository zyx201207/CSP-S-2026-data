#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],t1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cin>>a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			t1=a[i]-a[i-1];
		}
		if(t1<=d){
			cout<<n-3<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
