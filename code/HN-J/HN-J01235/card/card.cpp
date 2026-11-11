#include<iostream>
int n,m,a[500001],hp[500001],p[500001],nb[500001],tu[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;++i){
		int back=0;
		for(int i=1;i<=n;++i) nb[i]=0,hp[i]=0;
		for(int i=1;i<=m;++i) tu[i]+=p[i],p[i]=0;
		for(int j=i;j<=n;++j){
			if(nb[a[j]] && hp[nb[a[j]]]==a[j]){
				back=nb[a[j]];
				continue;
			}
			hp[++back]=a[j];
			if(!nb[a[j]]) nb[a[j]]=back;
		}
		for(int i=1;i<=back;++i){
			p[hp[i]]=1;
		}
	}
	++tu[a[n]];
	for(int i=1;i<=m;++i){
		printf("%d ",tu[i]);
	}
	return 0;
}
