//GZ-J00514 ÑîµÂÓî
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1,tot;
int a[501011],ans[301011],app[301011],sum[501011];
void push(int x){
	if(!app[x]) sum[++tot]=x,app[x]=true;
	else{
		int i=cnt;
		for(i=cnt;i<=tot && sum[i]!=x;i++);
		memset(app,false,sizeof(app));
		tot=i;
		for(i=cnt;i<=tot;i++) app[sum[i]]=true;
	}
}
void clear(){
	memset(sum,0,sizeof(sum));
	tot=0;
	cnt=1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	bool falg=true;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1] && i!=1) falg=false;
	}
	if(falg){
		for(int i=1;i<=n;i++) ans[a[i]]=i;
		for(int i=1;i<=m;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++) push(a[j]);
			for(int j=cnt;j<=m;j++) if(app[j]) ans[j]++,app[j]=false;
			clear();
		}
		for(int i=1;i<=m;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
