#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[3001],b[101][101],anss,ans;
void solve(long long s,long long t1,long long z,long long maxx){
	if(s==z){
		if(t1==maxx){
			anss++;
		}
		return;
	}
	if(t1>maxx){
		return;
	}
	for(int i=s+1;i<=z;i++){
		if(!b[s][i]){
			break;
		}
		solve(i,t1+1,z,maxx);
	}
}
int main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	scanf("%lld%lld",&c,&t);
	for(int k=1;k<=t;k++){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[j]-x[i])<=d){
					b[i][j]=1;
				}
			}
		}
		ans=0;
		for(int u=1;u<=n;u++){
			for(int v=u+2;v<=n;v++){
				anss=0;
				long long s=u,t1=0;
				while(s!=v){
					long long xc=s+1;
					while(b[s][xc]&&xc<=v){
						xc++;
					}
					xc--;
					if(xc==s){
						break;
					}
					s=xc;
					t1++;
				}
				solve(u,0,v,t1);
				if(anss==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1

*/
