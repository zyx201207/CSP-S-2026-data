#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in"," r",stdin);
	freopen("migrate.out","w",stdout);
	
	long long c,t,n,d;
	int x[1000001];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
	}
	for(int i=1;i<=n;i++){
		int y1=u;ym=v;
		if(v-u<=d){
			cout<<1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
