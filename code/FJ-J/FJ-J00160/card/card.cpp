#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],cnt[N],b[N],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)b[j]=c[j]=0;
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
				b[a[j]]=j;
				c[j]=a[j];
				continue;
			}
			for(int k=b[a[j]];k<j;k++)
				b[c[k]]=0;
			b[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
			if(b[j])cnt[j]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",cnt[i]);
}