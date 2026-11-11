#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ans;
const int M=1e5*5+5;
long long w[M];//地铁口至站厅
struct b{
	long long v[495];
}y[M];
long long f(long long st,long long en){
	//从st至en两个地铁站是否有直接路径 
	bool flag=0;
	long long dis=1e9;
	for(int i=1;i<=n;i++){
		if(y[st].v[i]>0&&y[en].v[i]>0){
			flag=1;	
			dis=min(dis,w[st]+y[st].v[i]+y[en].v[i]+w[en]);
		}
	}
	if(flag==0){
		return -1;
	}
	else{
		return dis;
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){ 
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){//地铁线路 
		long long k;
		scanf("%lld",&k); 
		for(int j=1;j<=k;j++){
			long long a1,t1;
			scanf("%lld %lld",&a1,&t1);
			y[a1].v[i]=t1;
		} 
	}
	for(int i=1;i<=q;i++){
		long long st,en;
		scanf("%lld %lld",&st,&en);
		long long ans=f(st,en);
		if(ans!=-1){
			printf("%lld\n",ans);
		}
		else{
			long long dis=1e9;
			for(int j=1;j<=m;j++){
				for(int s=1;s<=n;s++){
					for(int s1=1;s1<=n;s1++){
						if(y[st].v[s]>0&&y[j].v[s]>0&&y[j].v[s1]>0&&y[en].v[s1]>0){
							dis=min(dis,w[st]+y[st].v[s]+y[j].v[s]+y[j].v[s1]+y[en].v[s1]+w[en]);
						}
					}
					
				}
				
			}
			printf("%lld\n",dis);
		}
	} 
	return 0;
} 
