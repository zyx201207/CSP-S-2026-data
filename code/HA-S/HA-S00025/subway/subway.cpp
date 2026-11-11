#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,ans;
const int N=100005;
	int zhanshu[N];
	int luguo[N];
	int tim[N];




	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int tai[m];
	for(int i=1;i<=m;++i) cin>>tai[i];
	for(int j=3;j<=n+2;++j) {
	cin>>zhanshu[j];
	for(int j=3;j<=n+2;++j)
	cin>>luguo[j]>>tim[j];
}
for(int e=1;e<=q;++e){
 cin>>x>>y ;
ans=0;
	for(int i=1;i<=m;++i){
   	for(int j=1;j<=m;++j){
   		if(zhanshu[i]==x&&zhanshu[j]==y)  ans=tai[x]+tai[y];
	}	
	}else for(int u=1;u<=y;++u){
			ans=tai[x]+tai[y]+tim[u];
		cout<<ans<<endl;
	}



	cout<<ans;
}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 




