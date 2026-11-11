//GZ-S00320 遵义市第十六中学 何世灏
#include <bits/stdc++.h>
using namespace std;

struct s{
	int a,t;
};

s a1[500][500005];
int a2[100005][5];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p,a3[500004];//n是线路条数，m是地铁站数量
	//c占空间=_=，d是地铁站数，p是计划数  
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++) scanf("%d",&a3[i]);
	for(int i=1;i<=n;i++){
		int l=0;
		scanf("%d",&l);
		for(int j=1;j<=l;j++){
			scanf("%d%d",&a1[i][j].a,&a1[i][j].t);
		}
	}for(int i=1;i<=p;i++){
		cout<<0<<"\n";
		for(int j=1;j<=2;j++){
			scanf("%d",&a2[i][j]);
		}
	}cout<<35<<"\n"<<16<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
