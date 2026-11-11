#include<bits/stdc++.h>
using namespace std;
struct Str{
	int l,r;
	friend bool operator<(Str a,Str b){
		return a.l<b.l;
	}
}s[500005];
int a[500005],pos[300005],ans[300005];
bool vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,len=0,idx;
	bool f=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]<a[i-1])f=1;
		if(pos[a[i]])s[++len]={pos[a[i]],i};
		pos[a[i]]=i;
	}
	if(f){
		sort(s,s+len+1);
		for(int i=1;i<=n;i++){
			idx=i;
			for(int j=1;j<=m;j++)
				vis[j]=0;
			for(int j=1;j<=len;j++)
				if(s[j].l>=idx){
					for(int k=idx;k<s[j].l;k++)
						vis[a[k]]=1;
					idx=s[j].r;
				}
			for(int j=1;j<=m;j++)
				ans[j]+=vis[j];
		}
		for(int i=1;i<=m;i++)
			printf("%d ",ans[i]);
	}
	else{
		for(int i=2;i<=n;i++)
			if(a[i]!=a[i-1])printf("%d ",i-1);
		printf("%d",n);
	}
	return 0;
}
