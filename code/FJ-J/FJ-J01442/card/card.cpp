#include<bits/stdc++.h>
using namespace std;
int a[500005],f[500005],c[500005],t[500005],ans[500005],p[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i,j,top=0,pg=0;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]) pg=1;
		p[a[i]]=i;
		if(!c[a[i]]){
			c[a[i]]=i;
		}else{
			t[c[a[i]]]=i;
			c[a[i]]=i;
		}
	}
	if(pg==0){
		for(i=1;i<=m;i++){
			printf("%d ",p[i]);
		}
		return 0;
	}
//	for(i=1;i<=n;i++){
//		cout<<t[i]<<" ";
//	}
	for(i=1;i<=n;i++){
		j=i;
		while(j<=n){
			if(t[j]){
				j=t[j];
			}else{
				ans[a[j]]++;
				j++;
			}
		}
	}
	for(i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}