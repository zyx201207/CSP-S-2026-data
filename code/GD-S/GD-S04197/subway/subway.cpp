#include<bits/stdc++.h>
using namespace std;
int Subtask,n,m,d,q;
int w[500005];
int a[505][500005];
int k;
int u,val;
int Start,End;
long long ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&Subtask,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&u,&val);
			a[i][u]=val;
		}
	}
	for(int l=1;l<=q;l++){
		ans=0;
		scanf("%d%d",&Start,&End);
		ans+=w[Start]+w[End];
		for(int i=1;i<=n;i++){
			if(a[i][Start]&&a[i][End]){
				printf("%lld\n",ans+a[i][Start]+a[i][End]);
				break;
			}
		}
	}
	return 0;
 } 
