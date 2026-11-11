#include <bits/stdc++.h>
using namespace std;

int n,a[200001];
char s[200001],c;
long long sumn,sum=0,ans=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%c%c",&a[i],&c,&s[i]),sumn+=1LL*a[i];
	int x=1,y=n;
	while(a[x]>0 && a[y]>0){
		int z=min(a[x],a[y]);
		a[x]-=z; a[y]-=z;
		if(s[x]!=s[y])
			ans+=z;
		if(a[x]==0)
			x++;
		if(a[y]==0)
			y--;
	}
	printf("%lld\n",ans);
}
