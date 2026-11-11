#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=35;
int a[N],lst[N],nxt[N],p[N],_p[N],sl[N];
int cf[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	memset(lst,0,sizeof(lst));memset(nxt,0,sizeof(nxt));memset(sl,0,sizeof(sl));
	int len=0,sum=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sl[a[i]]++;
	for(int i=n;i>=1;i--)if(lst[a[i]]==0)lst[a[i]]=i;
	for(int i=1;i<=n;i++)if(i==lst[a[i]])p[++len]=a[i],_p[a[i]]=len;
	for(int i=n;i>=1;i--)if(i==lst[a[i]]){
		if((i+1)!=lst[a[i+1]])nxt[i]=i;
		else nxt[i]=nxt[i+1];
	}
	for(int i=1;i<=m;i++){
		int x=lst[i],y=0;
		while(x!=n+1){
			x=lst[a[x]];y=nxt[x];
			cf[_p[a[x]]]+=sl[i];cf[_p[a[y]]+1]-=sl[i];
			x=y+1;
		}
	}
	for(int i=1;i<=len;i++){
		sum+=cf[i];
		ans[p[i]]=sum;
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}
