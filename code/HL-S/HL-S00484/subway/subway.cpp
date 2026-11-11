#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1919810],k[502],a[502][500],t[502][500],x,y,ma[520][501],b[501][502][2],cc[501],e[500],f;
long long ans=1145141919810;
void aaa(int ss,int bb,int d[]){
	d[ss]=1;
	if(ss==y){
		ans=bb;
//		for(int i=1;i<=500;i++){
//			if(d[i]==1){
//				cout<<i<<' ';
//			}
//		}cout<<"AAAAA";

		return;
	}for(int i=1;i<=cc[ss];i++){
		for(int j=1;j<=k[b[ss][i][0]]&&k[b[ss][i][0]]>1;j++){
			if(bb+b[ss][i][1]+b[a[b[ss][i][0]][j]][i][1]<ans&&d[a[b[ss][i][0]][j]]!=1){
				e[++f]=a[j][i];aaa(a[b[ss][i][0]][i],bb+b[ss][i][1]+b[a[j][i]][i][1],d);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			b[a[i][j]][++cc[a[i][j]]][0]=i;b[a[i][j]][cc[a[i][j]]][1]=t[i][j];
		}
	}if(c<=6){
		while(q--){
			scanf("%d%d",&x,&y);ans=1145141919810;
			if(x==y){
				printf("0\n");
			}else{
				int d[501]={};
				aaa(x,0,d);
				printf("%d",ans+w[x]+w[y]);//cout<<ans<<' ';
				
			}
		}
	}
	
	
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



*/