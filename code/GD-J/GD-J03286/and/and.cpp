#include <bits/stdc++.h>
using namespace std;

int n,m,a[200001];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	int ma=0,id;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),ma=max(ma,a[i]);
	int sum=ma;
	for(int i=1;i<=n;i++)
		if(a[i]==ma)
			id=i;
	a[id]=0;
	for(int i=1;i<m;i++){
		int mma=0,maid;
		for(int j=1;j<=n;j++)
			if((a[j]&sum)>mma)
				mma=a[j]&sum,maid=j;
		sum=mma;
		a[maid]=0;
	}
	printf("%d\n",sum);
}
