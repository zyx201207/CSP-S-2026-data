#include<bits/stdc++.h>
using namespace std;
int n,m,l,a[500010],t[500010],q[500010],s[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n-i;++j)
			q[j]=0;
		l=0;
		for(int j=i;j<=n;++j){
			for(int k=1;k<=l;++k)
				if(a[j]==q[k]){
					for(int z=k;z<=l;++z)
						q[z]=0;
					l=k;
					break;
				}
			q[++l]=a[j];
		}
		for(int j=1;j<=l;++j)
			++s[q[j]];
	}
	for(int i=1;i<=m;++i)
		printf("%d ",s[i]);
	return 0;
}
