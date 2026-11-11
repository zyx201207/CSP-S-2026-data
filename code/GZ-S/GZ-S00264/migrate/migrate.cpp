//GZ-S00264 遵义市第四中学 董云旗 
#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int gc=x[2]-x[1];
		if(d!=2*gc)cout<<0<<endl;
		else cout<<n-3<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
