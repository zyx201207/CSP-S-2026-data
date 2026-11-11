#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],a,b[500010][30],teta,tetb[510],t;
int sum[510][510],ans,tb[500010][30];
int read(){
	int sum=0,k=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-'){
			k=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum=sum*10+(c-'0');
		c=getchar();
	}
	return sum*k;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		teta=read();
		for(int j=1;j<=teta;j++){
			a=read();
			t=read();
			tetb[a]++;
			b[a][tetb[a]]=i;
			tb[a][tetb[a]]=t;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=tetb[i];j++){
			for(int k=j+1;k<=tetb[i];k++){
				if(sum[b[i][j]][b[i][k]]!=0){
				    sum[b[i][j]][b[i][k]]=min(tb[i][j]+tb[i][k],sum[b[i][j]][b[i][k]]);
					sum[b[i][k]][b[i][j]]=min(tb[i][j]+tb[i][k],sum[b[i][k]][b[i][j]]);
				}else{
					sum[b[i][j]][b[i][k]]=tb[i][j]+tb[i][k];
					sum[b[i][k]][b[i][j]]=tb[i][j]+tb[i][k];
				}
			}
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			if(sum[i][j]!=0){
				for(int k=j+1;k<=n;k++){
					if(sum[j][k]!=0){
						if(sum[i][k]==0){
							sum[i][k]=sum[i][j]+sum[j][k];
							sum[k][i]=sum[i][j]+sum[j][k];
						}else{
							sum[i][k]=min(sum[i][k],sum[i][j]+sum[j][k]);
							sum[k][i]=min(sum[i][k],sum[i][j]+sum[j][k]);
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=0;
		for(int j=1;j<=tetb[x];j++){
			for(int k=1;k<=tetb[y];k++){
				if(ans!=0){
					ans=min(sum[b[x][j]][b[y][k]]+tb[x][j]+tb[y][k],ans);  
				}else{
					ans=sum[b[x][j]][b[y][k]]+tb[x][j]+tb[y][k];
				}
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}

