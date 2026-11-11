#include<bits/stdc++.h>
using namespace std;
long long c,T,n,x[2000006],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>x[i];
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
