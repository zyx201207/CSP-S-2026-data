#include<iostream>
#include<cstdio>
using namespace std;
int a[500001],b[300001],ne[500001],v[300001],vv[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=n;i;i--){
		if(v[a[i]]) ne[i]=ne[v[a[i]]];
		else ne[i]=i+1;
		v[a[i]]=i;
		x=i;
		while(x>0){
			if(vv[a[x]]!=i) b[a[x]]++,vv[a[x]]=i;
			x=ne[x];
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",b[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
