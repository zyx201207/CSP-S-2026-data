#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,maxm=1e3+10;
long long c,n,m,d,q,w[maxn],k[maxn],x,y,h,cnt,p1,p2,f;
bool flag=false;
struct node{
	
	int a,t;
}z[maxm][maxm];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++) scanf("%lld%lld",&z[i][j].a,&z[i][j].t);
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
		h=0;
		cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(z[i][j].a==x){
					cnt+=w[x];
					cnt+=z[i][j].t;
					h=z[i][j].a;
					p1=i;
					p2=j;
					break;
				}
			}
			if(h!=0) break;
		}
		for(int i=1;i<=k[p1];i++){
			if(z[p1][i].a==y){
				cnt+=z[p1][i].t;
				cnt+=w[y];
				printf("%lld\n",cnt);
				flag=true;
				break;
			}
		} 
		if(flag) continue;
		flag=false;
		for(int i=1;i<=k[p1];i++){
			for(int j=1;j<=k[p1+1];j++){
				if(z[p1][i].a==z[p1+1][j].a){
					cnt+=z[p1][i].t;
					cnt+=z[p1+1][j].t;
					p1+=1;
					p2=j; 
					break;
				}
			}
		}
		for(int i=1;i<=k[p1];i++){
			if(z[p1][i].a==y){
				cnt+=z[p1][i].t;
				cnt+=w[y];
				printf("%lld\n",cnt);
				flag=true;
				break;
			}
		}
		if(flag) continue;
		if(p1>1){
			for(int i=1;i<=k[p1];i++){
				for(int j=1;j<=k[p1-1];j++){
					if(z[p1][i].a==z[p1-1][j].a){
						cnt+=z[p1][i].t;
						cnt+=z[p1-1][j].t;
						p1-=1;
						p2=j; 
						break;
					}
				}
			}
			for(int i=1;i<=k[p1];i++){
				if(z[p1][i].a==y){
					cnt+=z[p1][i].t;
					cnt+=w[y];
					printf("%lld\n",cnt);
					flag=true;
					break;
				}
			}
		}
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
