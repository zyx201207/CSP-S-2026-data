#include<bits/stdc++.h>
using namespace std;
int n,m,ax;
int a[500001];
int b[300001];
int q[500001],qi;
int x[300001];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int l=i;
		for(int j=i;j<=n;j++){
			qi=a[j];
			q[l]=qi;
			if(b[qi]==0) b[qi]=l;
			else l=b[qi];
			l++;
			ax=max(ax,l);
		}
		for(int j=i;j<=l;j++) x[q[j]]++;
		for(int j=i;j<=ax;j++) b[j]=0;
	}
	x[1]--;
	for(int i=1;i<=m;i++) printf("%d ",x[i]);
	return 0;
} 

