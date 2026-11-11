#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,m;
int a[500005],b[500005],c[500005];
int ans[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	fill(b,b+200005,-1);
	fill(c,c+200005,-1);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(c[a[i]]!=-1){
			b[c[a[i]]]=i;
			c[a[i]]=i;
		}else{
			c[a[i]]=i;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			if(b[j]!=-1) {
				j=b[j];
				continue;
			}
			ans[a[j]]++;
			j++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
