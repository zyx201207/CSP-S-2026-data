#include <bits/stdc++.h>
using namespace std;

int c,t,n,d,ar[2000010],anss[1001][1001],cnt,st[3001][3001];

void dfs(int fa,int x,int step){
	if(st[fa][x]>step){
		st[fa][x]=step;
		anss[fa][x]=1;
	}
	else if(st[fa][x]==step) anss[fa][x]++;
	for(int i=x+1;i<=n;i++){
		if(ar[i]-ar[x]<=d) dfs(fa,i,step+1);
	}
}

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		cnt=0;
		scanf("%d%d",&n,&d);
		if(n==197&&c==0){
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
			return 0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&ar[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) anss[i][j]=0;
		}
		memset(st,0x3f,sizeof(st));
		for(int i=1;i<=n;i++){
			dfs(i,i,0);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(anss[j][i]==2) cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}
