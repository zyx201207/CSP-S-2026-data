#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		bool p[3005];
		memset(p,0,sizeof(p));
		for(int j=i;j<=n;j++){
			int l=n+1;
			for(int k=i;k<=j-1;k++){
				if(a[k]==a[j]&&!p[k]){
					l=k;
					break;
				}
			}
			for(int k=l;k<j;k++) p[k]=1;
		}
		for(int j=i;j<=n;j++){
			if(!p[j]) cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
	return 0;
}
