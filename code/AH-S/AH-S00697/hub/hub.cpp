#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,n,k,q[N],op[N],f[N],ans;
vector<int> a[N];
int check(){
	int Max=0,sum=0;
	for(int i=1;i<=n;i++) f[i]=0;
	for(int l,r,i=1;i<=n;i++){
		if(!op[i]||f[i]) continue;
        sum++,f[i]=1,q[0]=i,l=0,r=1;
		while(l<r){
			int u=q[l],len=a[q[l]].size(); l++;
			for(int i=0;i<len;i++)
			    if(op[a[u][i]]&&!f[a[u][i]])
			        f[a[u][i]]=1,q[r]=a[u][i],r++;
		}	
	}
	if(sum>2) return n;
	for(int l,r,j,i=1;i<=n;i++){
		if(op[i]) continue;
		for(int p=1;p<=n;p++) f[p]=0;
		q[0]=i,l=0,r=1;
		for(j=1;j<=n;j++){
			int m=r-l,flag=0;
			while(m--){
				int u=q[l],len=a[q[l]].size(); l++;
				for(int p=0;p<len;p++)
				    if(a[u][p]!=f[u]){
					    if(op[a[u][p]]==1){flag=1;break;}
					    f[a[u][p]]=u,q[r]=a[u][p],r++;
					}
			}
			if(flag) break;
		}
		Max=max(Max,j);
	}
	return Max;
}
void dfs(int x,int num){
	if(n-x+1+num<k||num>k) return;
	if(x>n){ans=min(ans,check());return;}
	op[x]=1;dfs(x+1,num+1);
	op[x]=0;dfs(x+1,num);
}
void work1(){
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) a[i].clear();
		for(int i=1;i<n;i++){
			int u,v; scanf("%d%d",&u,&v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
		ans=n; dfs(1,0);
		printf("%d\n",ans);
	}
}
void work2(){
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) a[i].clear();
		for(int i=1;i<n;i++){
			int u,v; 
			scanf("%d%d",&u,&v);
		}
		int m=n/2;
		if(k==n) printf("%d\n",0);
		else if(k>=m) printf("%d\n",1);
		else printf("%d\n",(m-k+3)/4+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c<=3){work1();return 0;}
	if(c==13||c==14){work2();return 0;}
	return 0;
}
