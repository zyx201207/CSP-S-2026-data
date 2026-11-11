#include<bits/stdc++.h>
using namespace std;
const int N = 3000050;
int n,m,a[N],st[N],len,sum[N],id[N],idx;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if(!id[a[i]]) id[a[i]] = ++idx;
	}
	for(int i=1;i<=n;i++){
		memset(st,0,sizeof(st));
		len = 0;
		for(int j=i;j<=n;j++){
			if(st[a[j]]){
				for(int k=st[a[j]]+1;k<=j-1;k++) st[a[k]] = 0;
			}
			else{
				st[a[j]] = i+len+1;
				len++;
			}
		}
		for(int j=i;j<=n;j++){
			if(st[a[j]]) sum[a[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",sum[id[a[i]]]);
	}
	return 0;
}
