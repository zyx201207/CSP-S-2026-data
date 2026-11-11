#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,s=0,w[2000005],dis[10005][10005],b[2000005];
void dfs(int x,int y){
	if(x==y){
		bool c=0;
		b[y]++;
		return;
	}
	for(int i=d;i>=1;i--){
		int xx=x+i;
		if(xx<=y){
			b[xx]++;
			dfs(xx,y);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		s=0;
		for(int j=1;j<=n;j++){
			cin>>w[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				dis[j][k]=w[k]-w[j];
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(dis[j][k]<=d||dis[j][k]%d==0)
					continue;
				dfs(j,k);
				bool c=0;
				if(b[k]==3)
					c=1;
				for(int l=j;l<=k;l++){
					if(b[l]>2)
						c=1;
				}
				if(c==0)
					s++;
				for(int l=j;l<=k;l++)
					b[l]=0;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}

