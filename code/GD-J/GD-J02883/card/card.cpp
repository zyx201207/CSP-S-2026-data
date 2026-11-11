#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		printf("%d ",n);
	//	sum[a[i]]++;
	}/*
	for(int i=n;i;i--){
		memcpy(tmp,sum,sizeof(sum));
		nxt[i]=tong[a[i]];
		if(tong[a[i]]==-1)
			tong[a[i]]=i;
		nxtans[i]=(nxt[i]!=-1?i:nxtans[i+1]);
		int pre=nxtans[i];
		//while(pre!=-1)
		//	tmp[tong]pre~nxt[pre]
	}*/
	return 0;
}

