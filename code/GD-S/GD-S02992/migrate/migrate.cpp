#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;

int c,t,n,d;
long long x[N]; 
int nxt[N],pre[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
		/*
		路径一 第一次飞 最远 第二次飞 任意距离
		路径二 第一次飞 任意距离 第二次飞 最远
		飞到的岛屿就是双径岛屿
		单径岛屿 距离非常短，一跳就能到or每一跳都是最远
		*/
		while(t--){
			memset(x,0,sizeof x);
			memset(nxt,0,sizeof nxt);
			memset(pre,0,sizeof pre);
			scanf("%d%d",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&x[i]);
			}
//			for(int i=1,j=1;i<=n&&j<=n;j++){
//				if(x[j]-x[i]>d){
//					i++;
//				}
//				nxt[i]=j;
//				if(j==n) j--,i++;
//			}
//			for(int i=n,j=n;i>=1&&j>=1;j--){
//				if(x[j]-x[i]>d) i--;
//				nxt[i]=j;
//				if(j==1) j++,i--;
//			}
			x[n+1]=x[n]+0x3f3f3f3f;
			for(int i=1,j=1;i<=n+1&&j<=n+1;j++){
				if(x[j]-x[i]>d&&x[j-1]-x[i]<=d){
					nxt[i]=j-1;
					pre[j-1]=i;
					i++;
				}
			}
			for(int i=1;i<=n;i++){
				cout<<nxt[i]<<' '<<pre[i]<<endl;
			}
			int cnt=0;
			for(int i=1,j=1;i<=n&&j<=n;j++){
//				cout<<nxt[i]<<' '<<pre[j]<<' '<<i<<' '<<j<<endl;
				if(nxt[i]<=pre[j]) i++;
				if(nxt[i]-pre[j]==1) cnt++;
				if(j==n) j--,i++;
			}
			printf("%d\n",cnt);
		} 
	return 0;
} 

/*
1 2
4 2
1 2 3 4
5 2
1 2 3 4 5 pass

1 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6 pass

1 2
6 3
0 1 2 3 4 7
8 3
0 1 2 4 8 10 11 13
*/
