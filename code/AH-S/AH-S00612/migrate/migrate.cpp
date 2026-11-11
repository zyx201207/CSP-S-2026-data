#include<iostream>
#include<stdio.h>
#include<queue>
#include<cstring>
using namespace std;
long long c,t;
long long n,d,x[20005],f[505][505],p[505][505],put[505][505],cont=0;
inline long long dfs(long long i,long long j){
	if(f[i][j]){return f[i][j];}
	int cntp=0;
	for(long long k=i+1;k<=j-1;k++){
		long long tpl=dfs(i,k);
		long long tpr=dfs(k,j);
		if(tpl!=-1&&tpr!=-1){
			long long pq=tpl+tpr;
			if(pq==p[i][j]){
				cntp++;
				if(cntp>2){cntp=-1;break;}
			}
		}
	}
	f[i][j]=cntp;
	return cntp;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		memset(f,0,sizeof(f));
		memset(put,0,sizeof(put));
		cont=0;
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(long long i=1;i<=n-2;i++){//p贪心最小
			for(long long j=i;j<=n;j++){
				if(j==i){p[i][j]=-1;}
				else if(j==i+1){
					if(x[j]-x[i]>d){
						p[i][j]=-1;
					}
					else{
						p[i][j]=1;
					}
				}
				else{
				long long qu=i+1,cnt=0,im=i;
				bool yet=true;
				while(true){
					if(x[qu]-x[im]>d&&qu-im>1){
						cnt++;
						qu--;
						im=qu;
					}
					else if(x[qu]-x[im]>d&&qu-im<=1){
						yet=false;
						break;
					}
					//cout<<"qu:"<<qu<<" im:"<<im<<"\n";
					if(qu<j){qu++;}
					else if(qu==j){cnt++;break;}
				}
				if(yet){
					p[i][j]=cnt;
					if(p[i][j]==1){
						f[i][j]=1;
					}
				}
				else{
					p[i][j]=-1;
					f[i][j]=-1;
				}
			}
			}
		//	cout<<"i:"<<i<<"\n";
		}
		for(long long i=1;i<=n-1;i++){
			if(x[i+1]-x[i]<=d){
				f[i][i+1]=1;
			}
		}
		//cout<<"\n\n\n0001";
		for(long long i=1;i<=n-2;i++){
			for(long long j=i+2;j<=n;j++){
				if(p[i][j]!=1){
				put[i][j]=dfs(i,j);
				//cout<<"search:("<<i<<" "<<j<<")\n";
				if(put[i][j]==2){
					cont++;
				//	cout<<"cont:"<<cont<<"\n";
				}
			}
			}
		}
		printf("%lld\n",cont);
	}
	return 0;
}
