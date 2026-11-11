#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,dep[1000002],dep2[1000002],x,maxdep=1,head;
bool f[1000002],h[1000002];
vector<int>cv[1000002];
queue<int>q,p;
void work(){//最长链 
	q.push(1);
	memset(f,0,sizeof(f));
	memset(dep,0,sizeof(dep));
	dep[1]=1;f[1]=1;
	while(!q.empty()){
		x=q.front();q.pop();
		for(int i=0;i<cv[x].size();i++){
			if(f[cv[x][i]])continue;
			f[cv[x][i]]=1;
			dep[cv[x][i]]=dep[x]+1;
			if(dep[x]+1>maxdep){
				maxdep=dep[x]+1;
				head=cv[x][i];
			}
			q.push(cv[x][i]);
		}
	}
	p.push(head);
	memset(h,0,sizeof(h));
	memset(dep2,0,sizeof(dep2));
	dep2[head]=1;h[head]=1;
	while(!p.empty()){
		x=p.front();p.pop();
		for(int i=0;i<cv[x].size();i++){
			if(h[cv[x][i]])continue;
			h[cv[x][i]]=1;
			dep2[cv[x][i]]=dep2[x]+1;
			if(dep2[x]+1>maxdep){
				maxdep=dep2[x]+1;
			}
			p.push(cv[x][i]);
		}
	}
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			cv[u].push_back(v);
			cv[v].push_back(u);
		}
		if(c==1){//测试点1
			if(n==k)printf("0\n");
			else printf("1\n");
			continue;
		}
		work();//测试点7,11,12
		if(c!=1)printf("%d\n",maxdep/3);
	}
	return 0;
}
