#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int flag[500010][510];
struct zhan{
	int we,wt[30]={},cnt=0;
}z[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>z[i].we;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a;
			cin>>z[a].wt[i];
			z[a].cnt++;
			flag[a][i]=1;
		}
	}
	while(p--){
		int s,e;
		cin>>s>>e;
		int f=0;
		for(int i=1;i<=n;i++){
			if(z[s].wt[i]!=0&&z[e].wt[i]!=0)f=i;
		}
		if(f!=0){
			cout<<z[s].we+z[s].wt[f]+z[e].wt[f]+z[e].we;
		}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
