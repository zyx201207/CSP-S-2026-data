#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	while(t--){
		memset(a,0,sizeof(a));
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[2]-a[1]>d){
			cout<<0<<endl;
		}
		else{
			
		}
	}
	return 0;
}
