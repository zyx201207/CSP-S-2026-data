//GZ-S00264 遵义市第四中学 董云旗 
#include <bits/stdc++.h>
using namespace std;
struct Z{
	int w,x[501],t[501],s;
}z[500001];
long long c,m,n,p,q,o,d,j[500001],cf,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>z[i].w;
	for(int i=1;i<=n;i++){
		cin>>o;
		for(int j=1;j<=o;j++){
			cin>>p;
			z[p].x[i]=1;
			cin>>z[p].t[j/2];
			z[p].s++;
		}
	}for(int i=1;i<=m;i++){
		if(z[i].s==2)cf=i;
	}for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(z[x].s==2){
			if(z[y].x[1]==1)cout<<z[x].w+z[x].t[1]+z[y].t[1]+z[y].w;
			else cout<<z[x].w+z[x].t[2]+z[y].t[2]+z[y].w;
		}if(z[y].s==2){
			if(z[x].x[1]==1)cout<<z[x].w+z[x].t[1]+z[y].t[1]+z[y].w;
			else cout<<z[x].w+z[x].t[2]+z[y].t[2]+z[y].w;
		}else{
			if(z[x].x[1]==z[y].x[1]&&z[x].x[1]==1)cout<<z[x].w+z[x].t[1]+z[y].t[1]+z[y].w;
			else if(z[x].x[1]==z[y].x[1]&&z[x].x[1]==0)cout<<z[x].w+z[x].t[2]+z[y].t[2]+z[y].w;
			else if(z[x].x[1]!=z[y].x[1]&&z[x].x[1]==0)cout<<z[x].w+z[x].t[2]+z[cf].t[1]+z[cf].t[2]+z[y].t[1]+z[y].w;
			else cout<<z[x].w+z[x].t[1]+z[cf].t[1]+z[cf].t[2]+z[y].t[2]+z[y].w;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
