//GZ-S00310 遵义市第十九中学  戴文博
#include <bits/stdc++.h>
using namespace std;
int w[510];//地面到地铁站厅的时间
int c,n,m,d,q;
vector<int> link[500010];
vector<int> stat[3]; 
int mp[100][500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    memset(mp,127,sizeof(mp));
    for(int i=1;i<=m;i++){
    	scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,b;
			scanf("%d%d",&a,&b);
			link[i].push_back(a);
			mp[a][i]=b;
		}
	}
	int ans1_2=1e9,ans2_1=1e9;
	for(int i=1;i<=n;i++){
		if(mp[1][i]+mp[2][i]<=ans1_2){
			ans1_2=mp[1][i]+mp[2][i];
		}
	}
	for(int i=1;i<=n;i++){
		if(mp[2][i]+mp[1][i]<=ans1_2){
			ans2_1=mp[2][i]+mp[1][i];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==1&&y==2){
			printf("%d\n",(ans1_2+w[1]+w[2]));
		}else if(x==2&&y==1){
      		printf("%d\n",(ans2_1+w[1]+w[2]));
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

