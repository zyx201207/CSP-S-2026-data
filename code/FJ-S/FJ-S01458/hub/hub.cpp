#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=111111,M=222222,INF=(1<<30);
LL head[N],d[N],point[N],f1[n][3],f2[n][3],k1[n][3],k2[n][3],u,v,cnt,sans;
LL n,k,t;
void fdfs(LL *b,LL *a,LL *kb,LL *ka){//a->b
	b[2]=min(b[2],max(b[0],min(a[0],a[1])));
	if(b[1]>max(b[0]-1,a[1]-cost)){
		b[1]=(b[0]-1,a[1]-cost);
		kb[1]=ka[1];
	}else if(b[1]==a[i]-cost){
		kb[1]=min(kb[1],ka[1]);
	}else{
		b[1]=max(b[1],a[0]) ;
	}
	if(b[1]<max(b[0]-1,max(a[0],-cost))){
		kb[1]=1;
		b[1]=max(b[0]-1,max(a[0],-cost));
	}
	b[0]=max(b[0],b[1]); 
	
}
LL 
LL f(LL cost){
	memset(f1,INF,sizeof(f1));
	memset(f2,INF,sizeof(f2));
	memset(k1,INF,sizeof(k1));
	memset(f2,INF,sizeof(k2));
	//³õÊ¼»¯f1,f2,k1,k2Îª0 
	dfs1(1,0);
	dfs2(1,0);
	return dfs3(1,0);;
}
int main(){
	cin>>t;
	while(t--){
		ans=INF;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			make(u,v);
			make(v,u);
		}
		LL l=-INF,r=INF;
		while(l+1<r){
			mid=(l+r)/2;
			if(f(mid)){
				r=mid;
			} else{
				l=mid;
			}
			f(r);
		}
		cout<<ans;
	} 
	return 0;
}
