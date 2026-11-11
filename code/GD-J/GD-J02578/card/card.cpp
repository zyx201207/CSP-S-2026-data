#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],b[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(ans,0,sizeof(ans));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=max(b[a[i]],i);j<=n;j++){
			ans[a[j]]++;
			j=b[a[j]];
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//Trick||Treat!
