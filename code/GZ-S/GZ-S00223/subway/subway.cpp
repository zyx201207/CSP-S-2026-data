//GZ-S00223 遵义市第四初级中学 王培祯
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t[10001][10001],t1[10001],w[10005],y[10001][10001],y5[10001],ans=0x3f3f3f3f,b[10001];
void h(int e,int cnt,int s){
	//cout<<s<<" ";
	if(s==e){
		ans=min(cnt,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(t[s][i]!=0){
			for(int j=1;j<=y5[i];j++){
				if(b[y[i][j]]==0){
					b[y[i][j]]=1;
					h(e,cnt+t[s][i]+t[y[i][j]][i],y[i][j]);
					b[y[i][j]]=0;
				}
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d",&c);
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&d);
	scanf("%d",&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>y5[i];
		for(int j=1;j<=y5[i];j++){
			scanf("%d",&y[i][j]);
			scanf("%d",&t[y[i][j]][i]);
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		scanf("%d",&s);
		scanf("%d",&e);
		ans=0x3f3f3f3f;
		//cout<<w[e]<<" "<<w[s]<<" ";
		h(e,w[e]+w[s],s);
		printf("%d\n",ans);
	}
	return 0;
}
