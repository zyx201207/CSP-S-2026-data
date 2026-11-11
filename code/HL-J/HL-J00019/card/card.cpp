#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],b[M],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,f=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i>1&&a[i]<a[i-1]) f=0;
		b[a[i]]=i;
	}
	if(f){
		for(int i=1;i<=m;i++){
			printf("%d ",b[i]);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			ans[a[j]]++;
			j=b[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}