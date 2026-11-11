#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N],ans[M],b[N],d[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=i;j<=n;j++){
			if(!d[a[j]] || b[d[a[j]]]!=a[j] || d[a[j]]>cnt){
				b[++cnt]=a[j];
				d[a[j]]=cnt;
			}
			else cnt=d[a[j]];
		}
		for(int j=1;j<=cnt;j++)ans[b[j]]++;
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}

