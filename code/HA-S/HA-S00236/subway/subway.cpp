#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int c,n,m,d,q;
int w[500010],fir[500010];
struct node{
	int k,a[10010],t[10010],maxn;
}line[510];
int solve(int st,int en){
	int ans=0,node=st;
	if(fir[st]==fir[en]){
		int p=fir[st];
		for(int i=1;i<=line[p].k;i++){
			if(line[p].a[i]==st) ans+=line[p].t[i];
			if(line[p].a[i]==en) ans+=line[p].t[i];
		}
	}
	else{
		int p=fir[node]-1;
		while(node!=en){
			p++;
			bool pd=false,pd2=false;
			for(int i=1;i<line[p].k;i++){
				if(line[p].a[i]==st){
					pd2=true;
				}
				if(pd2&&line[p].a[i]==en){
					ans=0;
					for(int j=1;j<=line[p].k;j++){
						if(line[p].a[j]==st){
							ans+=line[p].t[j];
							break;
						}
					}
					ans+=line[p].t[i];
					node=en;
					break;
				}
				if(line[p].a[i]==node){
					pd=true;
					ans+=line[p].t[i];
				}
				if(pd&&line[p].a[i]<=en&&line[p].a[i+1]>en&&line[p].a[i]!=node){
//					if(line[p].t[i]==line[p].maxn) i--;
					ans+=line[p].t[i];
					node=line[p].a[i];
					break;
				}
				else if(pd&&line[p].a[line[p].k]<=en){
//					if(line[p].t[line[p].k]==line[p].maxn){
//						ans+=line[p].t[line[p].k-1];
//						node=line[p].a[line[p].k-1];
//					}
//					else{
						ans+=line[p].t[line[p].k];
						node=line[p].a[line[p].k];
//					}
					break;
				}
			}
//			printf("%d %d\n",node,ans);
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&line[i].k);
		for(int j=1;j<=line[i].k;j++){
			scanf("%d%d",&line[i].a[j],&line[i].t[j]);
			if(fir[line[i].a[j]]==0) fir[line[i].a[j]]=i;
			line[i].maxn=max(line[i].maxn,line[i].t[j]);
		}
	}
	while(q--){
		int st,en,ans=0;
		scanf("%d%d",&st,&en);
		if(st>en) swap(st,en);
		ans+=w[st];
		ans+=w[en];
		ans+=solve(st,en);
		printf("%d\n",ans);
	}
	return 0;
}
