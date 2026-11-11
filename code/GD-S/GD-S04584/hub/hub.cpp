#include<bits/stdc++.h>
using namespace std;
long long a,k,n,vis[4005][4005],b[400005],kk,kkk,c,vv[4005],t,u,v;
void sou(int re,int we){
	for(int i=1;i<=n;i++){
		if(vis[re][i]==1){
			if(b[i]>we){
				b[i]=we;
				sou(i,we+1);
			}else if(b[i]==0){
				b[i]=we;
				sou(i,we+1);
			}
		}
	}
}
void dfs(int op,int num){
	vv[num]=op;
	if(num==k){
		for(int i=1;i<=k;i++){
			b[vv[i]]=1;
			sou(vv[i],1);
		}
		kk=0;
		for(int i=1;i<=n;i++){
			if(b[i]>kk){
				kk=b[i];
			}
		}
		if(kkk>kk){
			kkk=kk;
		}
		return ;
	}
	for(int i=op+1;i<=n;i++){
		dfs(i,num+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		kkk=100000001;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			vis[u][v]=1;
			vis[v][u]=1;
		}
		for(int i=1;i<=n-k+1;i++){
			dfs(i,1);
		}
		cout<<kkk<<endl;
	}
	return 0;
} 
